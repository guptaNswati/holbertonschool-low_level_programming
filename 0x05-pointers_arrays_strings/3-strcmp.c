#include "holberton.h"

/**
* *_strcmp - compares two strings.
* @s1: string to compare
* @s2: string to compared with
* Return: either 1, -1 or 0
**/

int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
