#include <stdio.h>

/**
 * main - Prints alphabets in lowercas, except q and e
 * Return: 0
 **/

int main(void)
{
        char l_letter = 97;

	while (l_letter <= 122)
        {
		if (l_letter == 101 || l_letter == 113) 
		{
			continue;
		}

		putchar(l_letter);
		
		l_letter++;
	}

        putchar('\n');

        return (0);
}
