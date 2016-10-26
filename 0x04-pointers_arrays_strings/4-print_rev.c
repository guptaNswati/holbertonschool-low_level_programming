#include "holberton.h"

/**
* print_rev -  prints a string, in reverse
* @s: a pointer to string
* Return: nothing
**/

void print_rev(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	for (i = i; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}
