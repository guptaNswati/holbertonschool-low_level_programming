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
* rev_string - reverses a string
* @s: a pointer to string
* Return: nothing
**/

void rev_string(char *s)
{
	char first, last;
	int i;
	int size = _strlen(s) - 1;

	for (i = 0; i < size; i++)
	{
		first = s[i];
		last = s[size - i];
		s[i] = last;
		s[size - i] = first;
	}
}
