#include "holberton.h"

/**
* *_strcat - concatenates two strings.
* @dest: string to be appended
* @src: string to be appended from
* Return: a pointer to the resulting string dest
**/

char *_strcat(char *dest, char *src)
{
	int i = 0;

	while (dest[i] != '\0')
	{
		i++;
	}

	while (*src != '\0')
	{
		dest[i++] = *src;
		src++;
	}
	dest[i] = '\0';
	return (dest);
}
