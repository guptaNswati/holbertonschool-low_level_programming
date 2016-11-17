#include <stdlib.h>
#include <Stdio.h>

/**
* main - prints its own opcode
* @argc: arguement count
* @argv: arguement
* Return: nothing but exit with 1 or 2 if fails
**/
void main(int argc, char *agrv[])
{
	int num;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	num = atoi(argv[1]);
	if (num < 0)
	{
		printf("Error\n");
		exit(2);
	}
