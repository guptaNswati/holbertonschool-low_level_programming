#include "holberton.h"

/**
* print_triangle - draws a triangle in the terminal.
* @size: size of triangle
* Return: nothing
**/

void print_triangle(int size)
{
	if (size > 0)
	{
		int count, space, hashs;

		count = 0;

		while (count < size)
		{
			space = count;

			while (space < size - 1)
			{
				_putchar(' ');
				space++;
			}
			hashs = 0;

			while (hashs <= count)
			{
				_putchar('#');
				hashs++;
			}
			_putchar('\n');
			count++;
		}
	}
	else
		_putchar('\n');
}
