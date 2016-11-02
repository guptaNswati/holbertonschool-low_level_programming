#include "holberton.h"

/**
* _strlen_recursion - finds the length of a string.
* @s: pointer to string
* Return: length of string
**/
int _strlen_recursion(char *s)
{
	int len;

	len = 0;
	if (*s == '\0')
	{
		return (len);
	}
	else
		len++;
	return (_strlen_recursion(s + 1));
}