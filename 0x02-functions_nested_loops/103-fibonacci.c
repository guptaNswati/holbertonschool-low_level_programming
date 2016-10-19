#include <stdio.h>

/**
* main - Finds and prints the sum of the even-valued terms
* Return: 0
**/

int main(void)
{
	long num1 = 1;
	long num2 = 2;
	long limit = 4000000;
	long fib_num = 0;
	long sum = 2;
	int skip_count;

	while (fib_num <= limit)
	{
		skip_count = 0;

		while (skip_count <= 2)
		{
			fib_num = num1 + num2;
			num1 = num2;
			num2 = fib_num;
			skip_count++;
		}
		if (fib_num % 2 == 0)
		{
			sum += fib_num;
		}
	}
	printf("%ld\n ", sum);
	return (0);
}
