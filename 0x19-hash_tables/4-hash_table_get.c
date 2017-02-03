#include "hash_tables.h"

/**
* hash_table_get - retrieves a value associated with a key
* @ht: hash table to look into
* @key: key to search for
* Return: key's value or NULL
**/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int indx;
	hash_node_t *tmp;

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
	return (NULL);
}
