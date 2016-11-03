#include "holberton.h"
#include <stdio.h>
/**
* is_prime_number - checks if a given number is prime
* @n: given number
* Return: 1 if number is prime else 0
**/
int is_prime_number(int n)
{
	int m;

	m = 2;
	if (n <= 1 || m >= n)
	{
		return (0);
	}
	if (n % m == 0)
	{
		return (1);
	}
	return (is_prime_number(n));
	m++;
}
