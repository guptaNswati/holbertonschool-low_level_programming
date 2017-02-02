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
			if (ht->array[i])
			{
				tmp = ht->array[i];
				while (tmp)
				{
					if (i < ht->size - 1)
						printf("'%s': '%s', ", tmp->key,
						       tmp->value);
					/* print format for last node */
					else if (i == ht->size - 1 && !tmp->next)
						printf("'%s': '%s'", tmp->key,
						       tmp->value);
					tmp = tmp->next;
				}
			}
		}
		printf("}\n");
	}
}
