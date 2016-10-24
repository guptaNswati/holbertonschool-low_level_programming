#include <string.h>
#include "holberton.h"

/**
* print_rev -  prints a string, in reverse
* @*s: a pointer to string
* Return: nothing
**/

void print_rev(char *s)
{
	int size = strlen(s) - 1;

	for (size = size; size >= 0; size--)
	{
		_putchar(s[size]);
	}
	_putchar('\n');
}
