#include "holberton.h"
#include <stdlib.h>

/**
* *str_concat - concatenates two strings
* @s1 - first string
* @s2 - second string
* Return: pointer to new space in memory or null
**/
char *str_concat(char *s1, char *s2)
{
	char *strDup;
	int i, j, size;

	i = j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
                j++;

	size = i + j;
	strDup = malloc(sizeof(char) * size);

	if (strDup == NULL)
		return (NULL);
	i = j = 0;
	while (s1[i] != '\0')
	{
		strDup[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
        {
                strDup[i] = s2[j];
                i++, j++;
        }
	strDup[i] = '\0';
	return (strDup);
}
