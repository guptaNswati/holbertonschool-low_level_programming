#include <stdio.h>

/**
* main - Finds and prints first 50 fibonacci numbers
* Return: 0
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
		fib_num = num1 + num2;
		if (count < 50)
		{
			printf("%ld, ", fib_num);
		}
		num1 = num2;
		num2 = fib_num;
		count++;
	}
	printf("\n");
	return (0);
}
