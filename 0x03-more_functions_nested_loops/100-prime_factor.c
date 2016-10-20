#include <stdio.h>

/**
* main - finds and prints the largest prime factor of the number 612852475143
* Return: 0
**/

int main(void)
{
	long int num1, test_num, least_factor;

	num1 = 2;
	least_factor = 2;
	test_num = 612852475143;

	while (test_num > num1)
	{
		if (test_num % num1 == 0)
		{
			least_factor = 2;
			test_num = test_num / num1;
			num1 = num1 * num1;
		}
		else
		{
			num1++;
		}
	}
	least_factor = num1;
	printf("%ld\n", least_factor);
	return (0);
}
