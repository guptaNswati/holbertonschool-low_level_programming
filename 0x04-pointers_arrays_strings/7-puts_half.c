#include "holberton.h"

/**
 * _strlen - returns the length of a string.
 * @s: a pointer to a char
 * Return: length of a string
 **/

int _strlen(char *s)
{
	int length, i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	length = i;
	return (length);
}

/**
* puts_half - prints half of a string,
* @str: a pointer to string
* Return: nothing
**/

void puts_half(char *str)
{
	int i;
	int size = _strlen(str);

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
