#include "holberton.h"

/**
*  _strspn - gets the length of a prefix substring
* @s: pointer to string
* @accept: pointer to substring
* Return: the number of bytes of accept
**/

unsigned int _strspn(char *s, char *accept)
{
	int j;
	unsigned int len, tmp;
	int i = 0;

	len = 0;
	while (s[i] != '\0')
	{
		tmp = len;
		j = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
			{
				len++;
			}
			j++;
		}
		if (tmp == len)
			return (len);
		i++;
	}
	return (len);
}
