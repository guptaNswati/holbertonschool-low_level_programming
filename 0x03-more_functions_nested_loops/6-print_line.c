#include "holberton.h"

/**
* print_line - draws a straight line in the terminal.
* @n: length of line
* Return: nothing
**/

void print_line(int n)
{
	if (n > 0)
	{
		int count;

		count = 0;

		while (count < n)
		{
			_putchar('_');
			count++;
		}
	}
		_putchar('\n');
}
