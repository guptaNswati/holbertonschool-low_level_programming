#include <stdio.h>

/**
 * main - Prints all possible combinations of single-digit numbers
 * Return: 0
 **/

int main(void)
{
        int num = 48;

	while (num < 57)
        {
                putchar(num);
		putchar(',');
		num++;
        }

	putchar(57);
        putchar('\n');

        return (0);
}
