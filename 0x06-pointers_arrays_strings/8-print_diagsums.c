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
	int i, j, leftSum, rigtSum;

	leftSum = 0;
	rigtSum = 0;

	for (i = 0; i < size * size; i += size + 1)
	{
		leftSum += a[i];
	}
	for (j = size - 1; j < (size * size) - 1; j += size - 1)
	{
		rigtSum += a[j];
	}
	printf("%d, %d\n", leftSum, rigtSum);
}
