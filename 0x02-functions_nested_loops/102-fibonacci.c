#include <stdio.h>

/**
* main - Finds and prints first 50 fibonacci numbers
* Return: 0
**/

int main(void)
{
	long num1, num2, fib_num;
	int count;

	num1 = 0;
	num2 = 1;
	count = 0;

	while (count < 50)
	{
		fib_num = num1 + num2;
		num1 = num2;
		num2 = fib_num;

		if (count != 49)
		{
			printf("%ld, ", fib_num);
		}
		else
			printf("%ld\n", fib_num);
		count++;
	}
	return (0);
}
