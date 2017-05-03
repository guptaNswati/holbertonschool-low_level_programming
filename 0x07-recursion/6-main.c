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

	r = is_prime_number(15);
	printf("15 %d\n", r);
	r = is_prime_number(2);
	printf("2 %d\n", r);
	r = is_prime_number(3);
	printf("3 %d\n", r);
	r = is_prime_number(0);
	printf("0 %d\n", r);
	r = is_prime_number(-25);
	printf("-25 %d\n", r);
	r = is_prime_number(-1);
	printf("-1 %d\n", r);
	r = is_prime_number(113);
	printf("113 %d\n", r);
	r = is_prime_number(7919);
	printf("7919 %d\n", r);
	return (0);
}
