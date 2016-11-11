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
* mulNums - multiply an array
* @str: array to be multiplied
* @len: len of str
* @n: multiplier
* Return: array with result
**/
char *mulNums(char *str, int len, int n)
{
	char *res;
	int k, mul;

	res = malloc(sizeof(char) * len + 1);
	if (res == NULL)
        {
                printError();
                exit(98);
	}
	k = 0;
	mul = 1;
        for (len; len >= 1; len--)
        {
                mul = ((str[len - 1] - '0') * n) + k;
                res[len] = (mul % 10) + '0';
                k = mul / 10;
        }
	if (k >= 0 && k <= 9)
		res[len] = k + '0';
	else
		res[len] = '0';
	return (res);
}
/**
* addNums - add two arrays of digits
* @str1: array 1
* @str2: array2
* @size: memory to allocate
* @len1: length of str1
* @len2: length of str2
* Return: pointer to char with sum
**/
char *addNums(char *str1, char *str2, int size, int len1, int len2)
{
	char *add;
	int sum, k;

	add = malloc(sizeof(char) * size + 1);
	if (add == NULL)
        {
                printError();
                exit(98);
        }
	sum = k = 0 ;
	for (size; size >= 1; size--)
	{
		sum = (str1[len1 - 1] - '0') + (str2[len2 - 1] - '0') + k;
                add[size] = (sum % 10) + '0';
                k = sum / 10;
		len1--, len2--;
	}
	if (k >= 0 && k <= 9)
                add[size] = k + '0';
        else
                add[size] = '0';
	return (add);
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
	int mul, tempMul, tsum, i, len1, len2, resLen, k;
	char *current, *temp, *res, *sum;

	if (argc < 3 || argc > 3)
	{
		printError();
		exit (98);
	}
	len1 = _strlen(argv[1]);
	len2 = _strlen(argv[2]);
	if (len1 == -1 || len2 == -1)
		exit(98);

	res = addNums(argv[1], argv[2], len1, len1, len2);
	printf("res is %s\n", res); 
/*	temp = mulNums(argv[1], len1, 5);
	printf("%s\n", temp); */
	return (0);
}
