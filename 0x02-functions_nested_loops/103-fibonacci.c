#include <stdio.h>

/**
* main - Finds and prints the sum of the even-valued terms
* Return: 0
**/

int main(void)
{
	long num1, num2, limit, fib_num, sum;

	num1 = 0;
	num2 = 1;
	fib_num = 0;
	limit = 4000000;
	sum = 0;

	while (fib_num < limit)
	{
		fib_num = num1 + num2;
		if (fib_num % 2 == 0)
		{
			sum += fib_num;
		}
		num1 = num2;
		num2 = fib_num;
	}
	printf("%ld\n", sum);
	return (0);
}
