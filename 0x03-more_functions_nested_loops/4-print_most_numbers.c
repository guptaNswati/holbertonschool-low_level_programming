#include "holberton.h"

/**
* print_most_numbers - prints the numbers, from 0 to 9, except 2 and 4
* Return: nothing
**/

void print_most_numbers(void)
{
	char num1;

	for (num1 = '0'; num1 <= '9'; num1++)
	{
		if (!(num1 == '2' || num1 == '4'))
		{
			_putchar(num1);
		}
	}
	_putchar('\n');
}
