#include "holberton.h"
#include <stdio.h>

/**
* print_diagsums - prints the sum of the two diagonals of a square matrix
* @a: pointer to 2d array
* @size: size of array
* Return: nothing
**/

void print_diagsums(int *a, int size)
{
	int i;
	long leftSum, rigtSum;

	leftSum = 0;
	rigtSum = 0;

	for (i = 0; i < size; i++)
	{
		leftSum += *(a + i * (size + 1));
		rigtSum += *(a + (i + 1) * (size - 1));
	}
	printf("%lu, %lu\n", leftSum, rigtSum);
}
