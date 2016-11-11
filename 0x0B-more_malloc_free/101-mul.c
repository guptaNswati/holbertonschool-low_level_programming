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
* _strlen - calculates length of passed string
* @str: pointer to char
* Return: length of string
**/
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			printError();
			return (-1);
		}
	}
	return (i);
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
	int mul, i, len1, len2, resLen, k;
	char *num1, *num2, *res;

	if (argc < 3 || argc > 3)
	{
		printError();
		exit (98);
	}
	len1 = _strlen(argv[1]);
	if (len1 == -1)
		exit(98);
	num1 = malloc(sizeof(char) * len1 + 1);
	if (num1 == NULL)
	{
		printError();
		exit(98);
	}
	len2 = _strlen(argv[2]);
	if (len2 == -1)
		exit (98);
	num2 = malloc(sizeof(char) * len2 + 1);
	if (num2 == NULL)
	{
		printError();
		free(num1);
		exit(98);
	}
	resLen = len1 + len2;
	res = malloc(sizeof(char) * resLen + 1);
	if (res == NULL)
	{
		printError();
                free(num1);
		free(num2);
                exit(98);
	}
	for (i = 0; i < len1; i++)
		num1[i] = argv[1][i];
	for (i = 0; i < len2; i++)
		num2[i] = argv[2][i];
	k = 0;
	/*for(reslen - 1; reslen >= 0; reslen--)
	{
	mul = (num1[len1 - 1] - '0') * (num2[len2 - 1] - '0'; */
	_putchar('\n');
	return (0);
}
