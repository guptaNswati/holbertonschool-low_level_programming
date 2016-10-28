#include "holberton.h"
#include <stdio.h>
#include <string.h>
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

	i = size_r;
	k = 0;
	m = 0;
	j = 0;
	h = 0;
	n2_s = 0;
	n1_s = 0;
	size_r -= 1;
	while (n1[j] != '\0')
	{
		j++;
	}
	while (n2[h] != '\0')
	{
		h++;
	}
	if (j > size_r || h > size_r || size_r == 0 ||
	    (j == size_r && h == size_r && ((n1[0] - '0') + (n2[0] - '0') > 9)))
	{
		return (0);
	}
	n2_s = h - 1;
	n1_s = j - 1;
	for (; size_r > 1; size_r--)
	{
		if (n1_s < 0)
			m = n2[n2_s] - '0' + k;
		else if (n2_s < 0)
			m = n1[n1_s] - '0' + k;
		else
			m = (n1[n1_s] - '0') + (n2[n2_s] - '0') + k;
		r[size_r] = (m % 10) + '0';
		k = m / 10 ;
		n1_s--;
		n2_s--;
	}

	if (k > 9)
	{
		return (0);
	}
	r[0] = k + '0';
	r[i] = '\0';
	return (r);
}
