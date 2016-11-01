#include "holberton.h"
#include <stdlib.h>
/**
* *_strstr - locates a substring.
* @haystack: pointer to string to search in
* @needle: pointer to substring to be searched
* Return: pointer to the beginning of the located substring, or NULL
**/

char *_strstr(char *haystack, char *needle)
{
	char *res;
	char *tmp = needle;

	while (*haystack != '\0')
	{
		needle = tmp;
		res = haystack;
		while (*needle != '\0' && *haystack != '\0' &&
		       *haystack == *needle)
		{
			needle++;
			haystack++;
		}
		if (*needle == '\0')
			return (res);
		haystack = res + 1;
	}
	return (NULL);
}
