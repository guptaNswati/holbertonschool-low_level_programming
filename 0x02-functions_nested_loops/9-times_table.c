#include "holberton.h"

/**
* times_table - function that prints the 9 times table, starting with 0.
* Return: nothing
**/

void times_table(void)
{
	int num, count, digit_1, digit_2, product;

	count = 0;

	while (count <= 9)
	{
		num = 0;
		while (num <= 9)
		{
			product = count * num;

			if (product < 10)
			{
				if (num > 0)
				{
					_putchar(',');
					_putchar(' ');
					_putchar(' ');
				}
				_putchar(product + '0');
			}
			else
			{
				_putchar(',');
				_putchar(' ');
				digit_2 = product % 10;
				digit_1 = product / 10;
				_putchar(digit_1 + '0');
				_putchar(digit_2 + '0');
			}
			num++;
		}
		_putchar('\n');
		count++;
	}
}
