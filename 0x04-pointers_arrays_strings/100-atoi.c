#include <string.h>
#include <stdio.h>
#include "holberton.h"

/**
* num_checker - checks if a given char is number or not
* @c: char to be checked
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
* * @*s: a pointer to a string
* Return: number of string, else 0
**/

int _atoi(char *s)
{
	int i, result;
	int length = strlen(s);

	for (i = 0; i < length; i++)
	{
		result = num_checker(s[i]);

		if (result == 1)
		{
			printf("number %c\n", s[i]);
		}
	}
	return (0);
}
