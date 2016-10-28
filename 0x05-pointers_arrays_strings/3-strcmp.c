#include "holberton.h"
#include <string.h>
/**
* *_strcmp - compares two strings.
* @s1: string to compare
* @s2: string to compared with
* Return: either 1, -1 or 0
**/

int _strcmp(char *s1, char *s2)
{
	return (strcmp(s1, s2));
/*
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
		return (15);
	if (i < j)
		return (-15);
		return (0); */
}
