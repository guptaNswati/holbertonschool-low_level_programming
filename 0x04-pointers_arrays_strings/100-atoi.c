#include <stdio.h>
#include "holberton.h"

/**
* _strlen - returns the length of a string.
* @s: a pointer to a char
* Return: length of a string
**/

int _strlen(char *s)
{
	int length, i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	length = i;
	return (length);
}

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
	int length = _strlen(s);

	neg = 0;
	num = 0;

	for (i = 0; i < length; i++)
	{
		if (s[i] == '-')
		{
			neg++;
		}

		isNum = num_checker(s[i]);

		if (isNum == 1)
		{
			num = 10 * num + (s[i] - 48);

			i = i + 1;
			while (i < length)
			{
				isNum = num_checker(s[i]);
				if (isNum != 1)
				{
					break;
				}
				else
				{
					num = 10 * num + (s[i] - 48);
					i++;
				}
			}
			break;
		}
	}
	if (neg % 2 != 0)
	{
		num *= -1;
	}
	return (num);
}
