#include "holberton.h"
#include <stdlib.h>
/**
* strtow - splits a string into words.
* @str: string to be splitted
* Return: pointer to an array of strings (words) or null
**/
char strtow(char *str)
{
	char **strDup;
	int i, j, k, n, words;

	i = words = 0;
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] != ' ')
		{
			while (str[i + j] != ' ')
				j++;
		}
		if (j != 0)
		{
			words += 1;
			i += j;
		}
		else
			i++;
	}
	strDup = malloc(sizeof(char) * words);
	k = 0;
	for (i = 0; i < words; i++)
	{
		while (str[k] != '\0')
		{
			j = 0;
			if (str[k] != ' ')
			{
				while (str[k + j] != ' ')
					j++;
			}
			if (j != 0)
			{
				strDup[i] = malloc(sizeof(char) * j);
				k += j;
				break;
			}
			else
				k++;
		}
	}

	if (strDup == NULL)
		return (NULL);

	k = 0;
	for (i = 0; i < words; i++)
        {
                while (str[k] != '\0')
                {
                        n = j = 0;
			if (str[k] != ' ')
                        {
                                while (str[k + j] != ' ')
				{
					strDup[i][n] = str[k + j];
                                        n++, j++;
				}
				strDup[i][n] = '\0';
                        }
                        if (j != 0)
			{
				k += j;
				break;
			}
                        else
                                k++;
                }
	}
	return (strDup);
}
