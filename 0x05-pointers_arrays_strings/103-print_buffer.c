#include "holberton.h"
#include <stdio.h>

/**
* print_buffer - prints a buffer.
* @b: pointer to string
* @size: total number of bytes
* Return: nothing
**/

void print_buffer(char *b, int size)
{
	int i;

	i = 0;

	/*while (i < size)
	  { */
		printf("%16p\n", b);
printf("%s\n", b);
/*	} */
}