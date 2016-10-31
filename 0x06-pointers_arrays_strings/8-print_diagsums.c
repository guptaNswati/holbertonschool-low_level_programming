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
	int i, j;
	long leftSum, rigtSum;

	leftSum = 0;
	rigtSum = 0;

	for (i = 0; i < size; i++)
	{
		
		leftSum += a[i][i];
	}
	printf("%lu, ",leftSum);

	for(j = (size - 1); j >= 0; j--)
	{
		
		rigtSum += a[j][j];
	}
	printf("%lu\n",rigtSum);
}
