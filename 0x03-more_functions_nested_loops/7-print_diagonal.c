#include "holberton.h"

/**
* print_diagonal - draws a diagonal line in the terminal.
* @n: length of line
* Return: nothing
**/

void print_diagonal(int n)
{
	if (n > 0)
	{
		int count, space_count;

		count = 0;

		while (count < n)
		{
			space_count = 0;
			while (space_count <= count)
			{
				_putchar(' ');
				space_count++;
			}
			_putchar('\\');
			_putchar('\n');
			count++;
		}
	}
	else
		_putchar('\n');
}
