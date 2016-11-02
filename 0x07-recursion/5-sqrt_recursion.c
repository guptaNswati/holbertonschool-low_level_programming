#include "holberton.h"

/**
* _sqrt_recursion - finds the natural square root of a number
* @n: given number
* Return: square root of n or -1
**/
int _sqrt_recursion(int n)
{
	int m;

	m = n;
	if (n <= 0)
	{
		return (-1);
	}
	if (n == 1)
	{
		return (1);
	}
	n = n/2;
	if (n*n == m)
	{
		return (n);
	}
	return (_sqrt_recursion(n - 1));
}
