#include <stdio.h>
#include "holberton.h"

/**
* a function that prints the 9 times table, starting with 0.
**/

void times_table(void)
{
	char num, count = '0';

	while (count <= '9')
	{
		for (num = num; num <= 9; num++)
		{
			_putchar(num);
			_putchar(',');
			_putchar(' ');
			_putchar('\n');
		}
		count++;
	}
}
