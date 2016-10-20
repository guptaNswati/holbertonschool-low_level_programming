#include <stdio.h>
/*#define BIGNUMBER 612852475143 */

/**
* main - finds and prints the largest prime factor of the number 612852475143
* Return: 0
**/

int main(void)
{
	int num1, test_num;

	test_num = 13;
	num1 = 2;

	while (test_num > num1)
	{
		if (test_num % num1 == 0)
		{
			test_num = test_num / num1;
			printf("test num is %d \n", test_num);
			printf("factor is %d \n", num1);
			num1 = 2;
		}
		else
		{
			num1++;
		}
	}
	printf("factor is %d \n", num1);
	return (0);
}
