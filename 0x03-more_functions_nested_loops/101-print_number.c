#include <stdio.h>
#include "holberton.h"

/**
* print_number - prints an int
* @n: int to be printed
* Return: nothing
**/

void print_number(int n)
{
	if (n >= 0 && n <= 9)
	{
		_putchar(n + '0');
	}
	else if (n >= -9 && n <= -1)
	{
		_putchar('-');
		_putchar(n + '0');
	}
	else
	{
		if (n < -9)
		{
			_putchar('-');
			n = n * -1;
		}
		while (n != 0)
		{
			_putchar(n % 10 + '0');
			n = n / 10;
		}
	}
}
