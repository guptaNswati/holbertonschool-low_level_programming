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
* *_strcpy - copies the string pointed to by src, including
* the terminating null byte (\0), to the buffer pointed to by dest
* @dest: a pointer to destination int
* @src: a pointer to src int
* Return: the pointer to dest
**/

char *_strcpy(char *dest, char *src)
{
	int i;
	char *strP;
	int length = _strlen(src);

	for (i = 0; i < length; i++)
	{
		dest[i] = src[i];
	}
	strP = dest;
	return (strP);
}
