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

    ht = shash_table_create(1024);
    shash_table_set(ht, "y", "0");
    shash_table_set(ht, "a", "0");
    shash_table_set(ht, "b", "0");
    shash_table_set(ht, "z", "0");
    shash_table_set(ht, "hetairas", "7");
    shash_table_set(ht, "serafins", "8");
    shash_table_set(ht, "depravement", "9");
    shash_table_set(ht, "heliotropes", "10");
    shash_table_set(ht, "neurospora", "11");
    shash_table_set(ht, "mentioner", "17");
    shash_table_set(ht, "stylist", "217");
    shash_table_set(ht, "subgenera", "17");
    shash_table_set(ht, "synaphea", "10");
    shash_table_set(ht, "joyful", "18");
    shash_table_print(ht);
    shash_table_print_rev(ht);

/*    shash_table_set(ht, "y", "0");
    shash_table_print(ht);
    shash_table_set(ht, "j", "1");
    shash_table_print(ht);
    shash_table_set(ht, "c", "2");
    shash_table_print(ht);
    shash_table_set(ht, "b", "3");
    shash_table_print(ht);
    shash_table_set(ht, "z", "4");
    shash_table_print(ht);
    shash_table_set(ht, "n", "5");
    shash_table_print(ht);
    shash_table_set(ht, "a", "6");
    shash_table_print(ht);
    shash_table_set(ht, "m", "7");
    shash_table_print(ht);
    shash_table_print_rev(ht); */
    return (EXIT_SUCCESS);
}
