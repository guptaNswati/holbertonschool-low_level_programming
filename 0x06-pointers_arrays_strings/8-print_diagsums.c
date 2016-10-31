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

	for (k = 0; k < size; k++)
	{
		for (i = 0; i < size; i++)
		{
			leftSum += a[i];
			printf("a[i] %d \n", a[k][i]);
		}
	}
	/* printf("%lu, ",leftSum); 

	for(j = (size - 1); j >= 0; j--)
	{
		rigtSum += a[j];
	}
	printf("%lu\n",rigtSum); */
}
