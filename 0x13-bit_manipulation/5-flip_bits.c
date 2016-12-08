#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
* flip_bits - counts number of bits needed to flip from 1 number to another
* @n: number to be fliped
* @m: number to be fliped to
* Return: number of bits needed
**/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count;
	unsigned long int num;

	count = 0;
	for (num = n ^ m; num != 0; num = num >> 1)
	{
		printf("num is %lu\n", num);
		count += (num & 1);
	}
	return (count);
}
