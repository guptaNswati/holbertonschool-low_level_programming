#include "holberton.h"
#include <stdio.h>

/**
* *infinite_add - adds two numbers
* @n1: pointer to number1
* @n2: pointer to number2
* @r: buffer to store result
* @size_r: buffer size
* Return: pointer to the result
**/

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, k, j, h, n2_s, n1_s, m;

	i = 0;
	m = 0;
	k = 0;
	j = 0;
	h = 0;
	n2_s = 0;
	n1_s = 0;

	while (n1[j] != '\0')
	{
		j++;
	}
	n1_s = j - 1;
	while (n2[h] != '\0')
	{
		h++;
	}
	n2_s = h - 1;
	for (; size_r > 0; size_r--)
	{
		m = (n1[n1_s] - '0') + (n2[n2_s] - '0') + k;
		if (m > 9)
		{
			r[size_r] = (m % 10) + '0';
			k = m / 10 ;
		}
		else if (m < 9 && m >= 0)
		{
			r[size_r] = m + '0';
		}
		n1_s--;
		n2_s--;
		/*	i++; */
	}
	r[0] = k + '0';
	/*r[i] = '\0'; */
	return (r);
}
