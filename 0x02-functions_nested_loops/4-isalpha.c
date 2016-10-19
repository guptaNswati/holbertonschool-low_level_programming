#include "holberton.h"

/**
*_isalpha - Checks for alphabetic characters,
* @c: int to be checked
* Description: irrespective of uppercase and lowercase
* Return: 1, on success
**/

int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}
