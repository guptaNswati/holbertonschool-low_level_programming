#include <stdio.h>

int add(int num1, int num2);
	
int main ()
{
	int num1 = 1;
	int num2 = 2;
	int sum;
	sum = add(num1, num2);
	printf("number 1 is %d and number 2 is %d\n", num1, num2);
	printf("sum is %d\n",sum);
	
	return (0);
}

int add (int num1, int num2)
{
	int result;
	result = num1 + num2;
	return result;
}

