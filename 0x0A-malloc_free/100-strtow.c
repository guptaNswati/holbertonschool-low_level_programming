#include "holberton.h"
#include <stdlib.h>
/**
* word_counter - counts number of words in 1d array of strings
* @str: pointer to char
* Return: number of words
**/
int word_counter(char *str)
{
	int i, words;

	i = words = 0;
	while (str[i] != '\0')
        {
		if (str[i] != ' ' && str[i + 1] != ' ')
		{
			return (1);
		}
		else if (str[i] == ' ' && str[i + 1] != ' ')
		{
			words += 1;
		}
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

/*	if (str == '\0')
	return (NULL); */
	words = word_counter(str);
/*	if (words < 1)
	return (NULL); */
	strDup = malloc(sizeof(char *) * words);
	if (strDup == NULL)
		return (NULL);
	k = 0;
	for (i = 0; i < words; i++)
	{
		while (str[k] != '\0')
		{
			n = 0;
			if (str[k] != ' ' && str[k + 1] != ' ')
			{
				strDup[i] = malloc(sizeof(char *) * k);
				if (strDup[i] == NULL)
                                {
                                        freeRows(strDup, i);
					return (NULL);
                                }
				else
				{
					strDup[i][n] = str[n];
                                        n++;
				}

			}
			else if (str[k] == ' ' && str[k + 1] != ' ')
			{
				strDup[i] = malloc(sizeof(char *) * n);
                                if (strDup[i] == NULL)
                                {
                                        freeRows(strDup, i);
                                        return (NULL);
                                }
                                else
                                {
                                        strDup[i][n] = str[n];
                                        n++;
                                }
			}
			k += n;
			break;
			k++;
		}
		strDup[i][n] = '\0';
	}
	strDup[i] = '\0';
	return (strDup);
}
