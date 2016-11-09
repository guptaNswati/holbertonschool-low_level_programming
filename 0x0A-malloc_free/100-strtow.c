#include "holberton.h"
#include <stdlib.h>
/**
* word_counter - counts number of words in 1d array of strings
* @str: pointer to char
* Return: number of words
**/
int word_counter(char *str)
{
	int i, j, words;

	i = words = 0;
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] != ' ')
			while (str[i + j] != ' ')
				j++;
		if (j != 0)
			words += 1, i += j;
		else
			i++;
	}
	return (words);
}
/**
* freeRows - free allocated spaces to array rows
* @strDup: pointer to pointer to char
* @i: number of rows to be freed
* Return: nothing
**/
void freeRows(char **strDup, int i)
{
	while (--i >= 0)
		free(strDup[--i]);
	free(strDup);
}
/**
* strtow - splits a string into words.
* @str: string to be splitted
* Return: pointer to an array of strings (words) or null
**/
char **strtow(char *str)
{
	char **strDup;
	int i, j, k, n, words;

	words = word_counter(str);
	if (words < 1)
		return (NULL);
	strDup = malloc(sizeof(char) * words);
	if (strDup == NULL)
		return (NULL);
	k = 0;
	for (i = 0; i < words; i++)
	{
		while (str[k] != '\0')
		{
			j = 0;
			if (str[k] != ' ')
				while (str[k + j] != ' ')
					j++;
			if (j != 0)
			{
				strDup[i] = malloc(sizeof(char) * j);
				if (strDup[i] == NULL)
				{
					freeRows(strDup, i);
					return (NULL);
				}
				n = 0;
				while (n < j)
					strDup[i][n] = str[k + n++];
				strDup[i][j] = '\0';
				k += j;
				break;
			}
			k++;
		}
	}
	strDup[i] = '\0';
	return (strDup);
}
