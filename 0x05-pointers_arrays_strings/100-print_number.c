#include "holberton.h"
/**
* check_zero - checks the number of zeros in the given int
* @n: number to be checked
* Return: number of zeros
**/
int check_zero(int n)
{
	int modNum = 10;
	int zeroCounter = 0;
	int forZero = 1000000000;

	if (n % modNum != 0)
		return (zeroCounter);
	while (modNum != forZero)
	{
		if (n % modNum == 0)
		{
			zeroCounter++;
			modNum *= 10;
		}
		else
			break;
	}
	return (zeroCounter);
}
/**
* print_number - prints an integer
* @n: int to be printed
* Return: nothing
**/
void print_number(int n)
{
	int dup, neg, zeros;

	dup = 0;
	neg = 1;
	if (n > 0)
	{
		neg *= -1;
		n *= -1;
	}
	if (n != 0)
	{
		zeros = check_zero(n);
		while (n != 0)
		{
			dup = dup * 10;
			dup = dup + n % 10;
			n = n / 10;
		}
		if (neg == 1)
			_putchar('-');
		while (dup != 0)
		{
			_putchar(-(dup % 10) + '0');
			dup = dup / 10;
		}
		if (zeros != 0)
		{
			while (zeros != 0)
			{
				_putchar('0');
				zeros--;
			}
		}
	}
	else
		_putchar('0');
}
