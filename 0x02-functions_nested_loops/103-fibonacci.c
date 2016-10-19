#include <stdio.h>

/**
* main - Finds and prints the sum of the even-valued terms
* Return: 0
**/

int main(void)
{
	long num1, num2, limit, fib_num, sum;

	num1 = 1;
	num2, sum = 2;
	limit = 4000000;
	fib_num = 0;

	int skip_count;

	while (fib_num < limit)
	{
		skip_count = 0;

		while (skip_count <= 2)
		{
			fib_num = num1 + num2;
			num1 = num2;
			num2 = fib_num;
			skip_count++;
		}
		sum += fib_num;
	}
	printf("%ld\n ", sum);
	return (0);
}
