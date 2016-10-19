#include "holberton.h"

/**
* print_times_table - prints the n times table, starting with 0.
* @n: the size of table to print to, max 15
* Return: nothing
**/

void print_times_table(int n)
{
	if (n < 0 || n > 15)
		;
	else
	{
		int num, count, product;

		count = 0;
		while (count <= n)
		{
			_putchar('0');
			num = 0;
			while (num <= n)
			{
				product = count * num;
				_putchar(',');
				_putchar(' ');
				if (product  < 10)
				{
					_putchar(' ');
					_putchar(' ');
					_putchar(product + '0');
				}
				else if (product < 100)
				{
					_putchar(' ');
					_putchar(product / 10 + '0');
					_putchar(product % 10 + '0');
				}
				else
				{
					_putchar(product / 100 + '0');
					_putchar(product % 100 / 10 + '0');
					_putchar(product % 10 + '0');
				}
				num++;
			}
			_putchar('\n');
			count++;
		}
	}
}
