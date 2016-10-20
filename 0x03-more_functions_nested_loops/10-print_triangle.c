#include "holberton.h"

/**
* print_triangle - draws a triangle in the terminal.
* @size size of triangle
* Return: nothing
**/

void print_triangle(int size)
{
	if (size > 0)
	{
		int count;

		count = 0;

		while (count < size)
		{
			_putchar('#');
			count++;
		}
	}
		_putchar('\n');
}
