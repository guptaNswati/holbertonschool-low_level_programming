#include <stdio.h>
#include "holberton.h"

/**
* print_to_98 - prints all natural numbers from n to a given number,
* followed by a new line.
* @n: number to start count from
* Return: nothing
**/

void print_to_98(int n)
{
	if (n <= 98)
	{
		while (n < 98)
		{
			printf("%d, ", n);
			n++;
		}
	}
	else
		while (n > 98)
		{
			printf("%d, ", n);
			n--;
		}
	printf("%d\n", n);
}
