#include <stdio.h>

/**
* main - prints the numbers, from 1 to 100
* for multiples of both three and five print FizzBuzz 10 times
* Return: 0
**/

int main(void)
{
	int num1;

	num1 = 1;

	for (num1 = 1; num1 <= 100; num1++)
	{
		if (num1 % 3 == 0 || num1 % 5 == 0 || num1 % 15 == 0)
		{
			if (num1 % 3 == 0 && num1 % 15 != 0)
			{
				printf("Fizz ");
			}
			else if (num1 % 5 == 0 && num1 % 15 != 0)
			{
				printf("Buzz ");
			}
			else if (num1 % 15 == 0)
			{
				printf("FizzBuzz ");
			}
		}
		else
			printf("%d ", num1);
	}
		printf("\n");
		return (0);
}
