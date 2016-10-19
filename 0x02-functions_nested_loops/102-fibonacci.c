#include <stdio.h>

/**
* main - Finds and prints first 50 fibonacci numbers
* Return: 0
**/

int main(void)
{
	long num1, num2, fib_num;

	num1 = 0;
	num2 = 1;
	fib_num = 0;

	int count;

	count = 0;
	while (count < 50)
	{
		fib_num = num1 + num2;
		printf("%ld", fib_num);
		if (count != 49)
		{
			printf(", ");
		}
		num1 = num2;
		num2 = fib_num;
		count++;
	}
	printf("\n");
	return (0);
}
