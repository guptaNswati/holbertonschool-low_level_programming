#include "holberton.h"

/**
* print_square - draws a sqaure in the terminal.
* @size: size of square
* Return: nothing
**/

void print_square(int size)
{
	if (size > 0)
	{
		int countIn, countOut;

		countOut = 0;

		while (countOut < size)
		{
			countIn = 0;
			while (countIn < size)
			{
				_putchar('#');
				countIn++;
			}
			_putchar('\n');
			countOut++;
		}
	}
	else
		_putchar('\n');
}
