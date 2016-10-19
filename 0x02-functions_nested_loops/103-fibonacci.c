#include <stdio.h>

/* function declartion for add_fib() */
long add_fib(long num1, long num2);

/**
* Finds and prints the sum of the even-valued terms
* Return: nothing
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
			fib_num = add_fib(num1, num2);
			num1 = num2;
			num2 = fib_num;
			skip_count++;
		}
		sum += fib_num;
	}
	printf("%ld\n ", sum);
	return (0);
}

/**
* add_fib - function returns the sum of two fib numbers
* @num1: first term
* @num2: second term
* Return: sum of first and second term
**/
long add_fib(long num1, long num2)
{
	long sum;

	sum = num1 + num2;

	return (sum);
}
