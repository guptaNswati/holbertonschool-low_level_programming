#include "hash_tables.h"

/**
* shash_table_create - creates an empty hash table of given size
* @size: size of the table
* Return: pointer to a new hash table
**/
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	if (size == 0)
		return (NULL);
	ht = NULL;
	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;
	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;
	return (ht);
}

/**
* add_node_sorted1 - add nodes in a sorted order in a linkedlist of a hashtable
* specifically adjusting sprev and next pointers
* @head: pointer to head of the list
* @tail: pointer to tail of the list
* @tmp: pointer to new node to be added
* Return: pointer to new node
**/
shash_node_t *add_node_sorted1(shash_node_t **head, shash_node_t **tail,
			       shash_node_t *tmp)
{
	shash_node_t *cur;

	if (!*head)
	{
		*head = tmp, *tail = tmp;
		return (tmp);
	}
	if (strcmp((*head)->key, tmp->key) > 0)
	{
		tmp->snext = *head, (*head)->sprev = tmp, *head = tmp;
		return (tmp);
	}
	cur = *head;
	while (cur->snext)
	{
		if (strcmp(cur->key, tmp->key) < 0 &&
		    strcmp(cur->snext->key, tmp->key) >= 0)
		{
			tmp->snext = cur->snext, cur->snext->sprev = tmp;
			cur->snext = tmp, tmp->sprev = cur;
			return (tmp);
		}
		cur = cur->snext;
	}
	cur->snext = tmp, tmp->sprev = cur, *tail = tmp;
	return (tmp);
}


/**
* shash_table_set - insert key/value pair in the sorted list at the right place
* @ht: pointer to hash table
* @key: pointer to key
* @value: pointer to value
* Return: 1 on success, 0 if fails
**/
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *tmp, *cur;

	if (!ht || !key || *key == '\0' || !value)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	if (ht->array[index])
	{
		cur = ht->array[index];
		while (cur)
		{
			if (strcmp(cur->key, (char *)key) == 0)
			{
				free(cur->value);
				cur->value = (char *)strdup(value);
				return (1);
			}
			cur = cur->next;
		}
	}
	tmp = malloc(sizeof(shash_node_t));
	if (tmp == NULL)
		return (0);
	tmp->key = (char *)strdup(key);
	if (tmp->key == NULL)
	{
		free(tmp);
		return (0);
	}
	tmp->value = (char *)strdup(value);
	if (tmp->value == NULL)
	{
		free(tmp->key);
		free(tmp);
		return (0);
	}
	tmp->sprev = tmp->snext = NULL;
	add_node_sorted1(&ht->shead, &ht->stail, tmp);
	tmp->next = ht->array[index], ht->array[index] = tmp;
	return (1);
}

/**
* shash_table_get - retrieves a value associated with a key
* @ht: hash table to find key into
* @key: key to be searched
* Return: key's value or NULL
**/
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int indx;
	shash_node_t *tmp;

	if (ht)
	{
		indx = key_index((const unsigned char *)key, ht->size);
		if (ht->array[indx])
		{
			tmp = ht->array[indx];
			while (tmp)
			{
				if (strcmp(tmp->key, (char *)key) == 0)
					return (tmp->value);
				tmp = tmp->next;
			}
		}
	}
	return (NULL);
}

/**
* shash_table_print - prints hash table using sorted list
* @ht: pointer to hash table
* Return: nothing
**/
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *cur;

	if (ht)
	{
		cur = ht->shead;
		printf("{");
		while (cur)
		{
			if (!cur->snext)
				printf("'%s': '%s'", cur->key, cur->value);
			else
				printf("'%s': '%s', ", cur->key, cur->value);
			cur = cur->snext;
		}
		printf("}\n");
	}
}
/**
* shash_table_print_rev - print the hash table keys/values in reverse order
* using the sorted linked list
* @ht: pointer to hash table
* Return: nothing
**/
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *cur;

	if (ht)
	{
		cur = ht->stail;
		printf("{");
		while (cur)
		{
			if (!cur->sprev)
				printf("'%s': '%s'", cur->key, cur->value);
			else
				printf("'%s': '%s', ", cur->key, cur->value);
			cur = cur->sprev;
		}
		printf("}\n");
	}
}

/**
* shash_table_delete - deletes a hash table
* @ht: pointer to hash table
* Return: nothing
**/
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *cur, *tmp;

	if (!ht)
		return;

	cur = ht->shead;
	while (cur)
	{
		tmp = cur;
		cur = cur->snext;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
		tmp = NULL;
	}
	free(ht->array);
	free(ht);
	ht = NULL;
}
