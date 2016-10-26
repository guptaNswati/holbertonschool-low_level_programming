#include <stdio.h>
#include "holberton.h"

/**
* print_array - prints n elements of an array of integers
* @a: a pointer to an int
* @n: the number of elements of the array to be printed
* Return: nothing
**/

void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (i != n - 1)
		{
			printf("%d, ", a[i]);
		}
		else
		{
			printf("%d\n", a[i]);
		}
	}
}
