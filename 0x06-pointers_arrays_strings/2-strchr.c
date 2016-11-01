#include "holberton.h"
#include <stdlib.h>
/**
* *_strchr - locates a character in a string
* @s: pointer to string
* @c: character to search for
* Return: pointer to the first occurrence of the c in s, or NULL
**/

char *_strchr(char *s, char c)
{
	char *j;
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			j = &s[i];
			return (j);
		}
		i++;
	}
	if (c == '\0')
	{
		j = &s[i];
		return (j);
	}

	return (NULL);
}
