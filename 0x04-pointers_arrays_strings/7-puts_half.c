#include <string.h>
#include "holberton.h"

/**
* puts_half - prints half of a string,
* @*str: a pointer to string
* Return: nothing
**/

void puts_half(char *str)
{
	int i;
	int size = strlen(str);

	if (size % 2 != 0)
	{
		i = (size / 2) + 1;
	}
	else
	{
		i = size / 2;
	}

	for (i = i; i < size; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
