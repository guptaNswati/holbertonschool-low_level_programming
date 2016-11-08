#include "holberton.h"
#include <stdlib.h>

/**
* *create_array - creates an array of chars, and initializes it with a char
* @size - size of the array
* @c: char to be initialized with
* Return: pointer to array or null
**/
char *create_array(unsigned int size, char c)
{
	char *str;

	str = malloc(size);

	if (str == NULL)
		return (NULL);
	else
		str[0] = c;
	return (str);
}