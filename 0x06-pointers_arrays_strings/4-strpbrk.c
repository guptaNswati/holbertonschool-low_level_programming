#include "holberton.h"
#include <stdlib.h>
/**
* *_strpbrk - searches a string for any of a set of bytes.
* @s: pointer to string to search in
* @accept: pointer to substring to be searched
* Return: pointer to match or null
**/
char *_strpbrk(char *s, char *accept)
{
	char *tmp = accept;

	while (*s != '\0')
	{
		accept = tmp;
		while (*accept != '\0')
		{
			if (*s == *accept)
			{
				return (s);
			}
			accept++;
		}
		s++;
	}
	return (NULL);
}
