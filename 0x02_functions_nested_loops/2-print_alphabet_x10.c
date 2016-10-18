#include "holberton.h"

/**
* print_alphabet_x10 - Prints lowercase alphabets 10 times
* Return: nothing
**/

void print_alphabet_x10(void)
{
	int outer_loop, inner_loop;

	for (outer_loop = 0; outer_loop < 10; outer_loop++)
	{
		for (inner_loop = 'a'; inner_loop <= 'z'; inner_loop++)
		{
			_putchar(inner_loop);
		}
		_putchar('\n');
	}
}

