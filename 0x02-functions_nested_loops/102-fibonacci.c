#include <stdio.h>

/* function declartion for add_fib() */
long add_fib(long num1, long num2);

/**
* main - Finds and prints first 50 fibonacci numbers
* Return: nothing
**/

int main(void)
{
	long num1 = 1;
	long num2 = 2;
	long fib_num;
	int count = 3;

	printf("%ld, %ld, ", num1, num2);
	while (count <= 50)
	{
		fib_num = add_fib(num1, num2);
		if (count < 50)
		{
			printf("%ld, ", fib_num);
		}
		else
			printf("%ld\n ", fib_num);

		num1 = num2;
		num2 = fib_num;
		count++;
	}
	return (0);
}

/**
* add_fib - sum two fibonacci numbers
* @num1: first sequence
* @num2: second term in sequence
* Return: sum of num1 and num2
**/
long add_fib(long num1, long num2)
{
	long sum;

	sum = num1 + num2;

	return (sum);
}
