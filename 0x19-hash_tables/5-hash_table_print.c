#include "hash_tables.h"

/**
* hash_table_print - prints a hash table
* @ht: pointer to hash table
* Return: nothing
**/
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *tmp;

	if (ht)
	{
		printf("{");
		for (i = 0; i < ht->size; i++)
		{
			tmp = ht->array[i];
			while (tmp)
			{
				printf("'%s': '%s'", tmp->key, tmp->value);
				if (tmp->next)
					printf(", ");
				tmp = tmp->next;
			}
		}
		printf("}\n");
	}
}
