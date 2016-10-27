#include "holberton.h"

/**
* *_strncpy - copies a string.
* @dest: string to be appended
* @src: string to be appended from
* @n: number of bytes from src
* Return: a pointer to the resulting string dest
**/

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	if (n <= 0)
	{
		return (dest);
	}

	i = 0;

	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i++] = '\0';
	}
	return (dest);
}
