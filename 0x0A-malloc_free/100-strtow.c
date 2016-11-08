#include "holberton.h"
#include <stdlib.h>

/**
* **strtow - splits a string into words.
* @str - string to be splitted
* Return: pointer to an array of strings (words) or null
**/
char **strtow(char *str)
{
	char **strDup;
	int i, j, k, size, words;

	i = j = words = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			j++;
		if(str[i + 1] != ' ')
			words++;
		i++;
	}
	strDup = malloc(sizeof(char) * words);

	for (i = 0; i < words; i++)
		strDup[i] = malloc(sizeof(char) * j);

	if (strDup == NULL)
		return (NULL);

	for (i = 0; i < words; i++)
	{
		for (k = 0; k < j; k++, str++)
			strDup[i][k] = *str;
	}
	strDup[i][k] = '\0';
	return (strDup);
}
