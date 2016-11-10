#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
/**
* word_counter - counts number of words in 1d array of strings
* @str: pointer to char
* Return: number of words
**/
int word_counter(char *str)
{
	if (str[0] != ' ')
		return (1 + word_counterRec(str, 1));
	return (word_counterRec(str, 1));
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
	if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0')
		return (1 + word_counterRec(str, i + 1));
	return (word_counterRec(str, i + 1));
}
/**
* lenCounter - creates an array of each words length
* @str: pointer to char
* @words: number of words
* Return: pointer to an int
**/
int lenCounter(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i + 1] != ' ')
			i++;
		else
			break;
	}
	if (i != 0)
		i++;
	return (i);
}
/**
* createString - creates strings from an array of chars
* @str: pointer to char
* @words: number of words
* Return: pointer to char
**/
char **createString(char *str, int words)
{
	char **arr;
	char *res;
	int i, j, n;

	arr = malloc(sizeof(char *) * words);
        if (arr == NULL)
                return (NULL);
	for (i = 0; i < words; i++)
	{
		n = lenCounter(str);
		res = malloc(sizeof(char *) * n);
		if (res == NULL)
		{
			while (--i >= 0)
				free(arr[--i]);
			free(arr);
			return (NULL);
		}
		for (j = 0; j < n; j++, str++)
		{
			res[j] = *(str);
		}
		res[j] = '\0';
		arr[i] = res;
		str++;
	}
	arr[i] = '\0';
	return (arr);
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
	if (words < 1)
		return (NULL);
	if (words == 1)
	{
		strDup = malloc(sizeof(char *) * words);
		if (strDup == NULL)
			return (NULL);
		n = 0;
		for (*str; *str != '\0'; n++, str++)
			*(strDup + n) = str;
		*(strDup + n) = '\0';
		return (strDup);
	}
	strDup = createString(str + 1, words);
	return (strDup);
}
