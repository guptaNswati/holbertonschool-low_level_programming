#include "hash_tables.h"

/**
* hash_table_delete - deletes a gievn hash table
* @ht: pointer to hash table
* Return: nothing
**/
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *cur, *tmp;

	if (!ht)
		return;
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i])
		{
			cur = ht->array[i];
			while (cur)
			{
				tmp = cur;
				cur = cur->next;
				free(tmp->key);
				free(tmp->value);
				free(tmp);
				tmp = NULL;
			}
		}
	}
	free(ht->array);
	free(ht);
	ht = NULL;
}
