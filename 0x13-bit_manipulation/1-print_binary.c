#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* print_binary - prints the binary representation of a number
* @n: number to be represented
* Return: nothing
**/
void print_binary(unsigned long int n)
{
	if (n == 0)
	{
		_putchar('0');
		return;
	}
	if (n == 1)
	{
		_putchar('1');
		return;
	}
	for (; n > 0; n = n >> 1)
	{
		if (n & 1)
			_putchar('1');
		else
			_putchar('0');
	}
}
