#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
* _putchar - writes the character c to stdout
* @c: The character to print
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
* printError - prints error message
* Return: nothing
**/
void printError()
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
}
/**
* printResult - prints result
* @result: takes an int
* Return: nothing
**/
void printResult(int result)
{
	if (result / 10)
	    printResult(result / 10);
	_putchar(result % 10 + '0');
}
/**
* main - multiplies two positive numbers and prints result or error
* @argc: arguement count
* @agrv: poinetr to arguements
* Return: 0 or exit with 98
**/
int main(int argc, char *argv[])
{
	int result, num, i, j;

	if (argc < 3 || argc > 3)
	{
		printError();
		exit (98);
	}
	result = 1;
	for (j = 1; j < argc; j++)
	{
		num = 0;
		for (i = 0; argv[j][i] != '\0'; i++)
		{
			if (argv[j][i] >= '0' && argv[j][i] <= '9')
				num = num * 10 + (argv[j][i] - '0');
			else
			{
				printError();
				exit (98);
			}
		}
		result *= num;
	}
	printResult(result);
	_putchar('\n');
	return (0);
}
