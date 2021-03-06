#include "hash_tables.h"

/**
* hash_table_print - prints a hash table
* @ht: pointer to hash table
* Return: nothing
**/
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i, j;
	hash_node_t *tmp;

	if (ht)
	{
		/* track last non null index starting from back */
		i = ht->size;
		while (i > 0)
		{
			if (ht->array[i - 1])
			{
				j = i - 1;
				break;
			}
			i--;
		}
		printf("{");
		for (i = 0; i <= j; i++)
		{
			if (ht->array[i])
			{
				tmp = ht->array[i];
				while (tmp)
				{
					printf("'%s': '%s'", tmp->key, tmp->value);
					if (i < j)
						printf(", ");
					if (i == j && tmp->next)
						printf(", ");
					tmp = tmp->next;
				}
			}
		}
		printf("}\n");
	}
}
