#include <stdio.h>

/**
* main - Prints numbers from 0 to 99
* Return: 0
**/

int main(void)
{
	int num1, num2;

	for (num1 = 48; num1 <= 57; num1++)
	{
		for (num2 = 48; num2 <= 57; num2++)
		{
			putchar(num1);
			putchar(num2);

			if (!(num1 == 57 && num2 == 57))
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');

	return (0);
}
