#include <stdio.h>
#include "holberton.h"

/**
* num_checker - checks if a given char is number or not
* @a: char to be checked
* Return: 1, if its a number, else 0
**/
int num_checker(char a)
{
	char num = '0';

	while (num <= '9')
	{
		if (a == num)
		{
			return (1);
		}
		num++;
	}
	return (0);
}

/**
*  _atoi - a function that convert a string to an integer.
* @s: a pointer to a string
* Return: number of string, else 0
**/
int _atoi(char *s)
{
	int i, num, neg, isNum;

	neg = 0;
	num = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
		{
			neg++;
		}

		isNum = num_checker(s[i]);

		if (isNum == 1)
		{
			num = 10 * num - (s[i] - '0');
			i = i + 1;
			while (s[i] != '\0')
			{
				isNum = num_checker(s[i]);
				if (isNum != 1)
				{
					break;
				}
				num = 10 * num - (s[i] - '0');
				i++;
			}
			break;
		}
	}
	if (neg % 2 == 0 && num != 0)
	{
		num = -num;
	}
	return (num);
}
