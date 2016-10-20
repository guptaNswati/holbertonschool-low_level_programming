#include <stdio.h>

/**
* main - finds and prints the largest prime factor of the number 612852475143
* Return: 0
**/

int main(void)
{
	long int num1, test_num;

	num1 = 2;
	test_num = 612852475143;

	while (test_num > num1)
	{
		if (test_num % num1 == 0)
		{
			test_num = test_num / num1;
			num1 = 2;
		}
		else
		{
			num1++;
		}
	}
	printf("factor is %ld\n", num1);
	return (0);
}
