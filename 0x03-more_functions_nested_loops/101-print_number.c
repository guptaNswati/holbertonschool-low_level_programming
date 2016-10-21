#include "holberton.h"

/**
* print_number - prints an int
* @n: int to be printed
* Return: nothing
**/

void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = n * -1;
	}
	if (n > 9)
	{
		int duplicate;

		duplicate = 0;

		while (n != 0)
		{
			duplicate = duplicate * 10;
			duplicate = duplicate + n % 10;
			n = n / 10;
		}

		while (duplicate != 0)
		{
			_putchar(duplicate % 10 + '0');
			duplicate = duplicate / 10;
		}
	}
	else
		_putchar(n + '0');
}
