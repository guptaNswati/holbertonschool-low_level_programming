#include <stdio.h>
#include "holberton.h"

/**
* a function that prints the last digit of a number.
* Returns: an int
**/

int print_last_digit(int n)
{
	int result;
	result = n % 10;
	return result;
}
