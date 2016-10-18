#include <stdio.h>
#include "holberton.h"

/**
* a function that prints the n times table, starting with 0.
* Return: nothing
**/

void print_times_table(int n)
{
	if (!(n < 0 || n > 15))
	{
		int num, count, digit_1, digit_2, digit_3, product;

		count = 0;
	
		while (count <= n)
		{
			num = 0;
			while (num <= n)
			{
				product = count * num;
			
				if (product > 9 && product < 100)
				{
					digit_2 = product % 10;
					digit_1 = product / 10;
					_putchar(digit_1 + '0');
					_putchar(digit_2 + '0');
				}
				else if ( product >= 100 && product < 1000)
				{
					digit_3 = product % 10;
					digit_2 = (product % 100) / 10;
                                        digit_1 = product / 100;
					_putchar(digit_1 + '0');
                                        _putchar(digit_2 + '0');
                                        _putchar(digit_3 + '0');
				}

				else 
				{
					_putchar(product + '0');
				}	 
			
				if (num < n)
				{
					_putchar(',');
					
					if (product <= 9)
					{
						_putchar(' ');
					        _putchar(' ');
						_putchar(' ');
				        }
					else if (product <= 99)
					{
                                                _putchar(' ');
                                                _putchar(' ');
					}
					else
						_putchar(' ');
				}
			
				num++;
			} 
			_putchar('\n');
			count++;
		}
	}
}
