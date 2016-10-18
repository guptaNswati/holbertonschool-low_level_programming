#include "holberton.h"

/**
* a function that prints all natural numbers from n to a given number, 
* followed by a new line.
* Returns: nothing
**/

void print_to_98(int n)
{
	
	int digit_1, digit_2;
	
	if (n < 98)
	{
		while (n < 98)
		{
			if (n > 9)
			{
			digit_1 = n / 10;
			digit_2 = n % 10;
			_putchar(digit_1 + '0');
			_putchar(digit_2 + '0');
			}
		       
				if (n >= 0 && n <= 9)
				{
					_putchar(n + '0');
				}
				if (n >= -9 && n <= -1)
				{
					_putchar('-');
					_putchar(n + '0');
				}
				if (n < -9 )
				{
					_putchar('-');
					digit_1 = n / 10;
			        	digit_2 = n % 10;
					_putchar(digit_1 + '0');
					_putchar(digit_2 + '0');
				}
			
			_putchar(',');
			_putchar(' ');
			n++;
		}
	}
	else if (n > 98)
	{
		while (n > 98)
		{
			digit_1 = n / 10;
                        digit_2 = n % 10;
                        _putchar(digit_1 + '0');
                        _putchar(digit_2 + '0');
			_putchar(',');
                        _putchar(' ');
			n--;
		}
	}
	digit_1 = n / 10;
	digit_2 = n % 10;
	_putchar(digit_1 + '0');
	_putchar(digit_2 + '0');
	_putchar('\n');
}
