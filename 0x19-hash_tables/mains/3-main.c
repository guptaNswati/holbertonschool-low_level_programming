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
	hash_table_t *ht;

	ht = hash_table_create(1024);
	hash_table_set(ht, "betty", "holberton");
	hash_table_set(ht, "betty", "holberton");
	hash_table_set(ht, "be", "holberton");
	hash_table_set(ht, "bet", "holberton");
	hash_table_set(ht, "hetairas", "collides");
	hash_table_set(ht, "heliotropes", "collides");
	hash_table_set(ht, "depravement", "collides");
	hash_table_set(ht, "mentioner", "something");
	hash_table_set(ht, "neurospora", "something");
	hash_table_set(ht, "serafins", "something");
	return (EXIT_SUCCESS);
}
