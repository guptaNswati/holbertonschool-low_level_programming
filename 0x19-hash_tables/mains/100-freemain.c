#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	shash_table_t *ht;
	char *key;
	char *value;

	ht = shash_table_create(1024);
	shash_table_set(ht, "c", "fun");
	shash_table_set(ht, "python", "awesome");
	shash_table_set(ht, "Jennie", "and Jay love asm");
	shash_table_set(ht, "N", "queens");
	shash_table_set(ht, "Asterix", "Obelix");
	shash_table_set(ht, "Betty", "Holberton");
	shash_table_set(ht, "98", "Battery Streetz");
	key = strdup("Tim");
	value = strdup("Britton");
	shash_table_set(ht, key, value);
	key[0] = '\0';
	value[0] = '\0';
	free(key);
	free(value);
	shash_table_set(ht, "98", "Battery Street"); 
	shash_table_set(ht, "hetairas", "Jennie");
	shash_table_set(ht, "hetairas", "Jennie Z");
	shash_table_set(ht, "mentioner", "Jennie");
	shash_table_set(ht, "hetairas", "Jennie Z Chu");
	shash_table_print(ht);
	shash_table_delete(ht);
	return (EXIT_SUCCESS);
}
