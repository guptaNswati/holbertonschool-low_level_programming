#include <stdio.h>

/* add() declaration */
int add(int num1, int num2);

/**
* main - Finds and prints the sum of even-valued fibonacci terms 
* less than 4 million
* Return: 0
**/

int main ()
{
	int num1, num2, sum, fib_num, skip_count;
	num1 = 1;
	num2, sum = 2;
       
	printf("%d, %d, \n",num1, num2);
	while (num2 <= 144)
	{
		/*skip_count = 0;
		while(skip_count <= 2)
		{ */
		       fib_num = add(num1, num2);
		       printf("fib_num is %d\n", fib_num);
		       num1 = num2;
		       num2 = fib_num;
		
		       /*   skip_count++;
			    }*/
		       /*	sum = sum + fib_num;
				printf("sum at loop pass %d\n", sum); */
	}
/*	printf("%d", sum); */
	return (0);
}

/* function returns the sum of two numbers */
int add(int num1, int num2)
{
	int sum;
	
	sum = num1 + num2;

	return sum;
}
 
