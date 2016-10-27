#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	char s1[98] = "Hello ";
	char s2[] = "World!\n";
	char *p;

	printf("s1 is %s\n", s1);
	printf("s2 is %s", s2);
	p = _strcat(s1, s2);
	printf("after change s1 %s", s1);
	printf("after change s2 %s", s2);
	printf("p is %s", p);
	return (0);
}
