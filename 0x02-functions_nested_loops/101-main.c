#include <stdio.h>
#include "holberton.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	int result;
	result = sum_multiples_3and5();
	printf("sum of multiples of 3 and 5 below 1024 is %d \n", result);
	return (0);
}
