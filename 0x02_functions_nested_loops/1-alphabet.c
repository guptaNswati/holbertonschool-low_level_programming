#include <stdio.h>
#include "holberton.h"

/**
* Prints lowercase alphabets
**/

void print_alphabet(void)
{
	char alphabet = 'a';
	
	while (alphabet <= 'z')
	{
		_putchar(alphabet);
		alphabet++;
	}
	_putchar('\n');
}
