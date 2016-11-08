#include "holberton.h"
#include <stdlib.h>
#include <string.h>
/**
* *argstostr - concatenates all arguements to the program
* @ac -  arguement count
* @av - pointer to arguements
* Return: pointer to new space in memory or null
**/
char *argstostr(int ac, char **av)
{
	char *strDup;
	int i, j, k, size;

	k = size = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			size++;
	}
	strDup = malloc(sizeof(char) * (ac + size));

	if (strDup == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
        {
		for (j = 0; av[i][j] != '\0'; j++)
		{
			strDup[k++] = av[i][j];
		}
	        strDup[k++] = '\n';
	}
	strDup[k] = '\0';
	return (strDup);
}
