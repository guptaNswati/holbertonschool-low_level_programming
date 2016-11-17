#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>

/**
* main - performs simple mathematical operations
* @argc: arguement count
* @argv: arguements
* Return: if succes 0, else exit with 98
**/
int main(int argc, char *argv[])
{
	int num1, num2, res;
	int (*result)(int, int);

	if (argc != 4)
	{
		printf("argc Error\n");
		exit(98);
	}
	result = get_op_func(argv[2]);
	if (result == NULL)
	{
		printf("operator Error\n");
		exit(99);
	}
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	res = result(num1, num2);
	if (res == -1)
	{
		printf("res Error\n");
		exit(100);
	}
	printf("%d\n", res);
	return (0);
}
