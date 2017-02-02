#include "hash_tables.h"
#include <math.h>

/**
* key_index - gives the index of a key using hash_djb2()
* @key: pointer to chars which is the key
* @size: size of the array of the hash table
* Return: index at which the key/value pair should be stored in the hash table
**/
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
