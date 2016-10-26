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
	int i = 0;
	int size = _strlen(s) - 1;

	while (i < size)
	{
		first = s[i];
		last = s[size];
		s[i] = last;
		s[size] = first;
		i++;
		size--;
	}
}
