#include "holberton.h"

/**
* print_number - prints an int
* @n: int to be printed
* Return: nothing
**/

void print_number(int n)
{
	long casted_n, duplicate;

	casted_n = n;
	duplicate = 0;

	if (casted_n < 0)
	{
		_putchar('-');
		casted_n = casted_n * -1;
	}
	if (casted_n > 9)
	{
		while (casted_n != 0)
		{
			duplicate = duplicate * 10;
			duplicate = duplicate + casted_n % 10;
			casted_n = casted_n / 10;
		}

		while (duplicate != 0)
		{
			_putchar(duplicate % 10 + '0');
			duplicate = duplicate / 10;
		}
	}
	else
		_putchar(casted_n + '0');
}
