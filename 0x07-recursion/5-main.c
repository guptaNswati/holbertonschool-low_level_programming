#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	int r;

	r = _sqrt_recursion(1);
	printf("1 %d\n", r);
	r = _sqrt_recursion(-1024);
	printf("-1024 %d\n", r);
	r = _sqrt_recursion(0);
	printf("0 %d\n", r);
	r = _sqrt_recursion(3);
	printf("3 %d\n", r);
	r = _sqrt_recursion(4);
	printf("4 %d\n", r);
	r = _sqrt_recursion(9);
	printf("9 %d\n", r);
	return (0);
}
