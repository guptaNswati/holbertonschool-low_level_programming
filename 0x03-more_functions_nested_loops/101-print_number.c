#include "holberton.h"

/**
* check_zero - checks the number of zeros in the given int
* @n: number to be checked
* Return: number of zeros
**/

int check_zero(int n)
{
	int modNum = 10;
	int zeroCounter = 0;

	while (modNum != 1000000000)
	{
		if (n % modNum == 0)
		{
			zeroCounter++;
		}
		else if (n % modNum != 0)
		{
			break;
		}
		modNum *= 10;
	}
	return (zeroCounter);
}

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
		if (check_zero(n) != 0)
		{
			int zeros = check_zero(n);

			while (zeros != 0)
			{
				_putchar('0');
				zeros--;
			}
		}
	}
	else
		_putchar(casted_n + '0');
}
