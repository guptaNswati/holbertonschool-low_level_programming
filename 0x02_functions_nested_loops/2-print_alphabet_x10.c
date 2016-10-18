#include <stdio.h>
#include "holberton.h"

/**
* Prints lowercase alphabets 10 times
**/

void print_alphabet_x10(void)
{
	int count = 0;
	while (count < 10)
	{
		print_alphabet();
		count++;
	}
}

