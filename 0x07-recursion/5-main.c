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

	r = _sqrt_recursion(30000000);
	printf("30000000 %d\n", r); 
	r = _sqrt_recursion(25000000);
	printf("25000000 %d\n", r);
	r = _sqrt_recursion(250000000);
        printf("250000000 %d\n", r);
	r = _sqrt_recursion(0);
	printf("0 %d\n", r);
	r = _sqrt_recursion(9000000);
	printf("9000000 %d\n", r);
	r = _sqrt_recursion(4);
	printf("4 %d\n", r);
	r = _sqrt_recursion(9);
	printf("9 %d\n", r);
	r = _sqrt_recursion(1);
        printf("1 %d\n", r);
	return (0);
}
