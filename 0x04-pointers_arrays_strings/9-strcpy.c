#include <string.h>
#include "holberton.h"

/**
* *_strcpy - copies the string pointed to by src, including
* the terminating null byte (\0), to the buffer pointed to by dest
* @*dest: a pointer to destination int
* @*src: a pointer to src int
* Return: the pointer to dest
**/

char *_strcpy(char *dest, char *src)
{
	int i;
	char *strP;
	int length = strlen(src);

	for (i = 0; i < length; i++)
	{
		dest[i] = src[i];
	}
	strP = dest;
	return(strP);
}
