#include <stdio.h>
#include <gmp.h>

/* add() declaration 
unsigned long long int add(unsigned long long int num1, unsigned long long int 
num2); */

/**
* main - Finds and prints first 98 fibonacci numbers
* Return: 0
**/

int main (int argc, char *argv[])
{
	mpz_t num1 = 83621143489848422977;
	mpz_t num2 = 135301852344706746049;
	int count = 3;
	mpz_t fib_num;

	mpz_init_set_str (num1, argv[1], 10);/* Assume decimal integers */
	mpz_init_set_str (num2, argv[2], 10);/* Assume decimal integers */
	mpz_add (fib_num, num1, num2);/* a=a+b */

	printf("%s + %s => %s\n",argv[1], argv[2], mpz_get_str (NULL, 10, num1));
/*	while (count <= 98)
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
	printf("\n"); */
	return (0);
}

/* function returns the sum of two numbers 
unsigned long long int add(unsigned long long int num1, unsigned long long int
 num2)
{
	unsigned long long int sum;
	
	sum = num1 + num2;

	return sum;
}*/
 
