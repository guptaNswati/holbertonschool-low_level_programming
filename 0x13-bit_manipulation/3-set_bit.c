#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
* set_bit - sets the value of a bit to 1 at a given index
* @n: pointer to an int
* @index: starting from 0, is the index of the bit you want to set
* Return: 1 if it worked, or -1 if an error occurred
**/
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int i;

	for (i = 0; i < sizeof(n); i++)
	{
		if (i == index)
		{
			/* whatever 2^index is, make it 1 */
			*n |= 1 << index;
			return (1);
		}
	}
	return (-1);
}
