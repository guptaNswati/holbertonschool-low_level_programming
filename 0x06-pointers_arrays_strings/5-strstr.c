#include "holberton.h"

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
		while (*needle != '\0')
		{
			if (*haystack == *needle)
			{
				res = haystack;
				while (*haystack == *needle)
				{
					needle++;
					haystack++;
				}
				return (res);
			}
			else
				break;
			needle++;
		}
		haystack++;
	}
	return ('\0');
}