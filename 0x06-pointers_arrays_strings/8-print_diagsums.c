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
	int i, j, k;
	long leftSum, rigtSum;
	int *b = a;

	leftSum = 0;
	rigtSum = 0;

		for (i = 0; i < size; i++)
		{
			leftSum += *(a + i * size + i);
			printf("a[i] %d \n", *(a + i * size + i));
		}
	printf("%lu, ",leftSum);

	size--;
	for(; size > 0; size--)
	{
		rigtSum += *(a + size * size + size);
		printf("a[i] %d \n", *(a + size * size + size));
	}
	printf("a[j] %d \n", *(a + size - 1 * size + size - 1));
	printf("%lu\n",rigtSum);
}
