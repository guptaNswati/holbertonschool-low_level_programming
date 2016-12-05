#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
* get_bit - returns the value of a bit at a given index
* @n: number to be traversed
* @index: starting from 0, is the index of the bit you want to get
* Return: the value of the bit at index or -1 if an error occured
**/
int get_bit(unsigned long int n, unsigned int index)
{
	int i, j;
	char *revrsbin, *bin, found;

	revrsbin = malloc(sizeof(char) * 1024);
	if (revrsbin == NULL)
		return (-1);
	i = 0;
	while (n != 0)
	{
		if (n & 1)
			revrsbin[i] = '1';
		else
			revrsbin[i] = '0';
		n = n >> 1;
		i++;
	}
	revrsbin[i] = '\0';

	bin = malloc(sizeof(char) * i);
	if (bin == NULL)
	{
		free(revrsbin);
		return (-1);
	}
	i--;
	j = 0;
	while (i >= 0)
	{
		bin[j] = revrsbin[i];
		if (j == index)
		{
			found = bin[j] - '0';
			free(revrsbin);
			free(bin);
			return (found);
		}
		i--, j++;
	}
	bin[j] = '\0';
	free(revrsbin);
	free(bin);
	return (-1);
 }
