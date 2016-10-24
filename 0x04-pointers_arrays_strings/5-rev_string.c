#include <string.h>
#include "holberton.h"

/**
* rev_string - reverses a string
* @*s: a pointer to string
* Return: nothing
**/

void rev_string(char *s)
{
	int i;
	int size = strlen(s);
	char revStr[20];

	for (i = 0; i < size; i++)
	{
		revStr[i] = s[size - i];
	}
}
