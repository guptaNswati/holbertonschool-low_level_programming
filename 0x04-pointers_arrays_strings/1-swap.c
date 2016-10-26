#include "holberton.h"

/**
* swap_int - swaps the values of two integers.
* @a: a pointer to an int
* @b: a pointer to an int
* Return: nothing
**/

void swap_int(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
