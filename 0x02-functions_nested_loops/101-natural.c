#include <stdio.h>

/**
* main - computes and prints the sum of all the multiples of 3 or 5
* below 1024
* Return: 0
**/

int main(void)
{
	int num, limit, result;

	limit = 1024;
	num = 5;
	result = 3;

	while (num < limit)
	{
		if (num % 3 == 0 || num % 5 == 0)
		{
			result += num;
		}
		num++;
	}

	printf("%d\n", result);
	return (0);
}
