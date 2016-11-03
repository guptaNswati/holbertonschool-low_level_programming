#include "holberton.h"

/**
* sqtRecursive - computes square root recursively
* @n: given number
* @m: comparison number
* Return: 1 if not found sqrroot, else sqrroot
**/
int sqtRecursive(int n, int m)
{
	if (n * n == m)
		return (n);
	if (n * n > m)
		return (sqtRecursive(n - 1, m));
	return (-1);
}


/**
* _sqrt_recursion - finds the natural square root of a number
* @n: given number
* Return: square root of n or -1
**/
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (sqtRecursive(n / 2, n));
}
