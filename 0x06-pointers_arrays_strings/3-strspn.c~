#include "holberton.h"
#include <stdio.h>
/**
*  _strspn - gets the length of a prefix substring
* @s: pointer to string
* @c: pointer to substring
* Return: the number of bytes of accept
**/

unsigned int _strspn(char *s, char *accept)
{
	char tmp;
	int j;
	unsigned int len = 0;
	int i = 0;
	tmp = '1';

	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j] && s[i] != tmp)
			{
				tmp = s[i];
				printf(" temp is %c\n", tmp);
				len++;
				printf("len is %d\n", len);
			}
			j++;
		}
		i++;
	}
	return (len);
}
