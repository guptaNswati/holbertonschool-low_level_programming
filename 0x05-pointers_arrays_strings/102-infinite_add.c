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
	int i, k, j, h, n2_s, n1_s, m, req;
	char *np, *mp;
	char nn[100];
	char mm[100];

	i = 0;
	m = 0;
	k = 0;
	j = 0;
	h = 0;
	n2_s = 0;
	n1_s = 0;
	req = 0;
	np = nn;
	mp = mm;

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
	if (n1_s < size_r - 1)
	{
		int a, b, c, dif;

		dif = (size_r - 1) - n1_s;
		n1_s = dif + n1_s;
		b = 0;
		c = 0;
		for (a = 0; a < dif; a++)
		{
			nn[a] = '0';
		}
		while (n1[b] != '\0')
		{
			nn[a++] = n1[b++];
		}
		nn[a] = '\0';
	}
	else
	{
		np = n1;
	}

	if (n2_s < size_r - 1)
	{
		int a, b, c, dif;

                dif = (size_r - 1) - n2_s;
		n2_s = dif + n2_s;
                b = 0;
                c = 0;
                for (a = 0; a < dif; a++)
                {
                        mm[a] = '0';
                }
                while (n2[b] != '\0')
                {
                        mm[a++] = n2[b++];
                }
                mm[a] = '\0';
        }
        else
        {
                mp = n2;
        }


	for (; size_r > 0; size_r--)
	{
		m = (np[n1_s] - '0') + (mp[n2_s] - '0') + k;
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

	if (k > 9)
	{
		return (0);
	}
	r[0] = k + '0';
	/*r[i] = '\0'; */
	return (r);
}
