#include "holberton.h"

/**
* *cap_string - 6-cap_string.c
* @a: pointer to string
* Return: a pointer to the resulting string
**/

char *cap_string(char *a)
{
	int i;

	i = 1;

	while (a[i] != '\0')
	{
		if ((a[i - 1] == ' ' || a[i - 1] == '\t' || a[i - 1] == '\v'
		     || a[i - 1] == '\n' || a[i - 1] == ',' || a[i - 1] == ';'
		     || a[i - 1] == '.' || a[i - 1] == '!' || a[i - 1] == '?'
		     || a[i - 1] == '"' || a[i - 1] == '(' || a[i - 1] == ')'
		     || a[i - 1] == '{' || a[i - 1] == '}')
		     && (a[i] >= 'a' && a[i] <= 'z'))
		{
			a[i] = a[i] - 32;
		}
		i++;
	}
	return (a);
}
