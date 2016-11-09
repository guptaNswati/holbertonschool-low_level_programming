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
* currentIndex - tracks current char index
* @str: pointer to array
* @index: current index
* Return: next index
**/
int currentIndex(char *str, int index)
{
	int len;

	len = 0;
	while (str[index] != '\0')
        {
                if (str[index] == ' ' && str[index + 1] != ' ')
		{
			printf("str[i] %c\n", str[index]);
			len++;
		}
		else
			break;
		index++;
	}
	printf("len is %d\n", len);
	return (len);
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
	int j, n;

	n = currentIndex(str, 1);
	if (n != 0)
	{
		res = malloc(sizeof(char *) * n);
		if (res == NULL)
		{
			while (--m >= 0)
				free(twoD[--m]);
			free(twoD);
			return (NULL);
		}
		for (j = 0; j < n; j++, str++)
		{
			res[j] = *str;
			printf("res[j] is %c\n", res[j]);
		}
		*str = str[n];
	}
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
	if (words < 1)
		return (NULL);
	if (words == 1)
	{
		strDup = malloc(sizeof(char *) * words);
		if (strDup == NULL)
			return (NULL);
		for (n = 0; *str != '\0'; n++, str++)
			strDup[n] = str;
		strDup[n] = '\0';
		return (strDup);
	}
	strDup = malloc(sizeof(char *) * words);
	if (strDup == NULL)
		return (NULL);

	for (i = 0; i < words; i++)
	{
		printf("i is %d\n", i);
		strDup[i] = createString(str, i, strDup);
		if (strDup[i] == NULL)
			return (NULL);
	}
	strDup[i] = '\0';
	return (strDup);
}
