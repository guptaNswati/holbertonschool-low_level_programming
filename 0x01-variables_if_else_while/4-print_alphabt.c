#include <stdio.h>

/**
* main - Prints alphabets in lowercas, except q and e
* Return: 0
**/

int main(void)
{
        char l_letter = 'a';
	do
	{
		if (l_letter == 'e' || l_letter == 'q')
		{
			continue;
		}

		putchar(l_letter);
		l_letter++;

	} while (l_letter <= 'z');

        putchar('\n');

        return (0);
}
