#include "holberton.h"

/**
* *_strcmp - compares two strings.
* @s1: string to compare
* @s2: string to compared with
* Return: either 1, -1 or 0
**/

int _strcmp(char *s1, char *s2)
{
	int i, j;

	i = 0;
	j = 0;

	while (s1[i] != '\0')
	{
		i++;
	}
	while (s2[j] != '\0')
	{
		j++;
	}
	if (i > j)
		return 1;
	else if (i < j)
		return -1;
	return(0);
}
