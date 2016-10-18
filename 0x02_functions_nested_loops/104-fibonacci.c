#include <stdio.h>
#include <limits.h>

/* add() declaration */
unsigned long long int add(unsigned long long int num1, unsigned long long int 
num2);

/**
* main - Finds and prints first 98 fibonacci numbers
* Return: 0
**/

int main (void)
{
	unsigned long long int num1 = 1;
	unsigned long long int num2 = 2;
	int count = 3;
	unsigned long long int fib_num;

	printf("%llu, %llu, ",num1, num2);
	while (count <= 98)
	{
		if (fib_num > ULONG_MAX / num2)
		{
			printf("warning: overflow \n");
		}
		else
		fib_num = add(num1, num2);
		printf("fib num %d is %llu, ", count, fib_num);
		num1 = num2;
		num2 = fib_num;
	        
		count++;
	}
	printf("%lu\n", ULONG_MAX);
	printf("\n");
	return (0);
}

/* function returns the sum of two numbers */
unsigned long long int add(unsigned long long int num1, unsigned long long int
 num2)
{
	unsigned long long int sum;
	
	sum = num1 + num2;

	return sum;
}
 