#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/**
* main - generates random valid passwords for the program 101-crackme
* Return: 0
**/

int main(void)
{
	int i, l_limit, u_limit, sum, last;
	char last_c;
	time_t t;
	char alphnum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char randStr[20];
	char str2[21];
	l_limit = 0;
	u_limit = 2772;
	sum = 0;
	i = 0;
	srand((unsigned) time(&t));

	while (sum <= (u_limit - 122))
	{
		randStr[l_limit] = alphnum[rand() % (sizeof(alphnum) -1)];
		sum += randStr[l_limit];
		printf("%c\n", randStr[l_limit]);
		l_limit++;
	}

	last = u_limit - sum;
	last_c = (char)last;

	while (i <= 20)
	{
		str2[i] = randStr[i];
		i++;
	}
	str2[21] = last_c;

	printf("sum is %d\n", sum);
	printf("rem %d\n", last);
	printf("char %c\n", last_c);
	printf("%s \n", str2);
	return (0);
}
		