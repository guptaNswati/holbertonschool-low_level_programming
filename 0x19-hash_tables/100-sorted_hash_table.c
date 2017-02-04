#include "hash_tables.h"

/**
* shash_table_create - creates an empty hash table of given size
* @size: size of the table
* Return: pointer to sorted hash table
**/
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	if (size == 0)
		return (NULL);
	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);
	ht->array = malloc(sizeof(shash_node_t) * size);
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
* add_node_sorted1 - adds nodes in a sorted order in a linkedlist of a hashtable
* specifically adjusting sprev and next pointers
* @head: pointer to head of the list
* @tmp: pointer to new node to be added
* Return: pointer to new node
**/
shash_node_t *add_node_sorted1(shash_node_t **head, shash_node_t *tmp)
{
	shash_node_t *cur;

	/* add firsts */
	if (!*head)
		*head = tmp;
	else if (!(*head)->next)
	{
		if (strcmp((*head)->key, tmp->key) < 0)
		{
			(*head)->next = tmp;
			tmp->sprev = *head;
		}
		else
		{
			tmp->next = *head;
			(*head)->sprev = tmp;
			*head = tmp;
		}
	}
	else
	{
		/* add in between */
		cur = *head;
		while (cur->next)
		{
			if (strcmp(cur->key, tmp->key) >= 0)
			{
				tmp->next = cur;
				tmp->sprev = cur->sprev;
				cur->sprev->next = tmp;
				cur->sprev = tmp;
				break;
			}
			else if (strcmp(cur->key, tmp->key) < 0 &&
			    strcmp(cur->next->key, tmp->key) >= 0)
			{
				tmp->next, tmp->snext = cur->next;
				tmp->sprev = cur;
				cur->next->sprev = tmp;
				cur->next = tmp;
				break;
			}
			cur = cur->next;
		}
		/* add last */
		cur->next = tmp;
		tmp->sprev = cur;
	}
	return (tmp);
}

/**
* add_node_sorted2 - adds nodes in a sorted order in a linkedlist of a hashtable
* specifically adjusting sprev and snext pointers
* @head: pointer to head of the list
* @tmp: pointer to new node to be added
* Return: pointer to new node
**/
shash_node_t *add_node_sorted2(shash_node_t **head, shash_node_t *tmp)
{
	shash_node_t *cur;
	/* head's key less/eqaul to tmp key*/
	if (strcmp((*head)->key, tmp->key) >= 0)
	{
	        tmp->snext = *head;
		if (*head)
			(*head)->sprev = tmp;
		*head = tmp;
 		return (tmp);
	}
	/* add in between */
	cur = *head;
	while (cur->snext)
	{
		/* if cur is smaller than tmp add in between */
		if (strcmp(cur->key, tmp->key) > 0 &&
		    strcmp(cur->snext->key, tmp->key) <= 0)
		{
			tmp->sprev = cur;
			tmp->snext = cur->snext;
			cur->snext->sprev = tmp;
			cur->snext = tmp;
			return (tmp);
		}
		cur = cur->snext;
	}
	/* add last */
	cur->snext = tmp;
	tmp->sprev = cur;
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
	shash_node_t *tmp;

	if (!ht || !key)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
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
	tmp->sprev, tmp->next, tmp->snext = NULL;
	/* if a new entry add via shead */
	if (!ht->array[index])
		ht->array[index] = add_node_sorted1(&ht->shead, tmp);
	/* collison happened, add new entry to the list in sorted order */
	else
		add_node_sorted2(&ht->array[index], tmp);
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
				tmp = tmp->snext;
			}
		}
	}
	return (NULL);
}

/**
* shash_table_print -  print the hash table using the sorted linked list
* @ht: pointer to hash table
* Retunr: nothing
**/
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *cur, *tmp;

	if (ht)
	{
		cur = ht->shead;
		printf("{");
		while (cur)
		{
			/* iterate on sorted list of current node */
			tmp = cur;
			while (tmp)
			{
				if (!cur->next && !tmp->snext)
					printf("'%s': '%s'", tmp->key, tmp->value);
				else
					printf("'%s': '%s', ", tmp->key, tmp->value);
				tmp = tmp->snext;
			}
			cur = cur->next;
		}
		printf("}\n");
	}
}

/**
* - print the hash tables key/value pairs in reverse order using the sorted linked list
**/
void shash_table_print_rev(const shash_table_t *ht)
{
}
