#include "holberton.h"

/**
* *_memcpy - copies memory area
* @dest: pointer to memory to copy
* @src: pointer to memory to copy from
* @n: bytes of the memory area
* Return: pointer to dest
**/

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
