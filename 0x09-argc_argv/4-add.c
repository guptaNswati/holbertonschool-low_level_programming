#include <stdio.h>
#include <stdlib.h>

/**
* main - add positive numbers
* @argc: arguement count
* @argv: array of pointers to arguement strings
* Return: result of addition or 1
**/
int main(int argc , char *argv[])
{
	int i, num, sum;

	sum = 0;
	for (i = 1; i < argc; i++)
	{
		num = atoi(argv[i]);
		if (num <= 0)
		{
			printf("Error\n");
			return (1);
		}
		sum += num;
	}
	printf("%d\n", sum);
	return (0);
}
