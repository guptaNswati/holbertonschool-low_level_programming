#include <stdio.h>
#include "holberton.h"

/**
* print_last_digit - a function that prints the last digit of a number.
* @n: int to be evaluated
* Return: last digit of param
**/

int print_last_digit(int n)
{
	int result;

	result = n % 10;

	if (result < 0)
	{
		result *= -1;
	}
	_putchar('0' + result);
	return (result);
}
