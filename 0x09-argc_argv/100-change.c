#include <stdio.h>
#include <stdlib.h>

/**
* main - prints the minimum number of coins to make change for a given amount
* @argc: arguement count
* @argv: array of pointers to arguement strings
* Return: number of coins or 1
**/
int main(int argc , char *argv[])
{
	int amount, coins;

	amount = atoi(argv[1]);
	coins = 0;
	if (argc != 2 || amount <= 0)
	{
		printf("Error\n");
		return (1);
	}
	if (amount == 1 || amount == 2 || amount == 5 ||
	    amount == 10 || amount == 25)
	{
		printf("%d\n", 1);
	}
	if (amount > 25)
	{
		while (amount >= 25)
		{
			amount -= 25;
			coins++;
		}
		coins++;
	}
	if (amount > 10 && amount < 25)
	{
		while (amount >= 10)
		{
			amount -= 10;
			coins++;
		}
		coins++;
	}
	if (amount > 5 && amount < 10)
	{
		while (amount >= 5)
		{
			amount -= 5;
			coins++;
		}
		coins++;
	}
	if (amount > 2 && amount < 5)
	{
		while (amount >= 2)
		{
			amount -= 2;
			coins++;
		}
		coins++;
	}
	if (amount == 1)
	{
		coins++;
	}
	printf("%d\n", coins);
	return (0);
}
