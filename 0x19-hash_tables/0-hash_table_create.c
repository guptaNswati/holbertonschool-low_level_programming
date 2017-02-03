#include "hash_tables.h"

/**
* hash_table_create - create a hash table
* @size: size of the table
* Return: pointer to the table
**/
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hshTbl;
	unsigned long int i;

	if (size == 0)
		return (NULL);
	hshTbl = malloc(sizeof(hash_table_t));
	if (hshTbl == NULL)
		return (NULL);
	hshTbl->array = malloc(sizeof(hash_node_t *) * size);
	if (hshTbl->array == NULL)
	{
		free(hshTbl);
		return (NULL);
	}
	for (i = 0; i < size; i++)
		hshTbl->array[i] = NULL;
	hshTbl->size = size;
	return (hshTbl);
}
