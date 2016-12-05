#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
* binary_to_uint - converts a binary number to an unsigned int
* @b: is pointing to a string of 0 and 1 chars
* Return: converted number, or 0
**/
unsigned int binary_to_uint(const char *b)
{
	unsigned int res;
	int i, j;

	if (b == NULL || (*b != '0' && *b != '1'))
		return (0);

	/* calculate the length of string to start from last digit */
	i = 0;
	while (b[i] != '\0')
		i++;

	res = j = 0;
	i--;
	while (i >= 0)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		/* left shift operand for multiplying by 2^i */
		res += (b[i] - 48) * (1 << j);
		i--, j++;
	}
	return (res);
}
