#include "holberton.h"

/**
* function that computes and prints the sum of all the multiples of 3 or 5 
* below 1024
* Return: an int
**/

int sum_multiples_3and5()
{
	int num_3 = 3;
	int num_5 = 5;
	int num_15 = 15;
	int limit = 1020;
	int sum_3, sum_5, sum_15 = 0;
	int result;

	while (num_3 <= limit)
	{
		sum_3+= num_3;
		num_3+=3;
	}
	while (num_5 <= limit)
        {
                sum_5+= num_5;
                num_5+=5;
        }
	while (num_15 <= limit)
        {
		sum_15+= num_15;
		num_15+=15;
	}
	result = (sum_3 + sum_5 + 1023) - sum_15;
	return result;
}
