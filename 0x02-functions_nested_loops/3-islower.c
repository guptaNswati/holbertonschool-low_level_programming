#include "holberton.h"

/**
* _islower -  Checks for lowercase character
* @c: int to be checked
* Return: 1, on success
**/

int _islower(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	return (0);
}
