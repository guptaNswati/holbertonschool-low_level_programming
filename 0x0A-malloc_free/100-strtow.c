#include "holberton.h"
#include <stdlib.h>
/**
* word_counter - counts number of words in 1d array of strings
* @str: pointer to char
* Return: number of words
**/
int word_counter(char *str)
{
	if (str[0] != ' ')
		return (1 + word_counterRec(str, 0));
	return (word_counterRec(str, 0));
}
/**
* word_counterRec - count num of words recursively
* @str: pointer to char
* @i: current index
* Return: number of words
**/
int word_counterRec(char *str, int i)
{
	if (str[i] == '\0')
		return (0);
	if (str[i] == ' ' && str[i + 1] != ' ')
		return (1 + word_counterRec(str, i + 1));
	return (word_counterRec(str, i + 1));
}
/**
* createString - creates strings from an array of chars
* @str: pointer to char
* @m: cuurent word index in 2d array
* @twoD: 2d array
* Return: pointer to char
**/
char *createString(char *str, int m, char **twoD)
{
	char *res;
	int j, n, i;

	n = i = 0;
	while (str[i] != ' ')
	{
		i++, n++;
	}
	res = malloc(sizeof(char *) * n);
	if (res == NULL)
	{
		while (--m >= 0)
			free(twoD[--m]);
		free(twoD);
		return (NULL);
	}
	for (j = 0; j < n; j++, str++)
		res[j] = *str;

	res[j] = '\0';
	return (res);
}
/**
* strtow - splits a string into words.
* @str: string to be splitted
* Return: pointer to an array of strings (words) or null
**/
char **strtow(char *str)
{
	char **strDup;
	int i, k, n, words;

	words = word_counter(str);
	strDup = malloc(sizeof(char *) * words);
	if (strDup == NULL)
		return (NULL);

	if (words == 1)
	{
		for (k = 0; str[k] != '\0'; k++)
			;
		strDup[0] = malloc(sizeof(char *) * k);
		if (strDup[0] == NULL)
		{
			free(strDup[0]);
			free(strDup);
			return (NULL);
		}
		n = 0;
		while (*str != '\0')
		{
			strDup[0] = str;
			n++, str++;
		}
		strDup[0][n] = '\0';
		return (strDup);
	}
	for (i = 0; i < words; i++)
	{
		while (*str != '\0')
		{
			if (*(str) != ' ' && *(str + 1) != ' ')
				strDup[i] = createString(str, i, strDup);
			if (strDup[i] == NULL)
				return (NULL);
		}
	}
	strDup[i] = '\0';
	return (strDup);
}
