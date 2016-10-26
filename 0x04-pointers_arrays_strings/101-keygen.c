#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
* main - generates random valid passwords for the program 101-crackme,
* sum = 2772
* Return: 0
**/

int main(void)
{
	int i, l_limit, u_limit, sum;
	char last_c;

	char alphnum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnop";
	char randStr[40];

	l_limit = 2772 - 122;
	u_limit = 2772;
	sum = 0;
	i = 0;
	srand(time(NULL));

	while (sum < l_limit)
	{
		randStr[i] = alphnum[rand() % (sizeof(alphnum) - 1)];
		sum += randStr[i];
		i++;
	}

	last_c = u_limit - sum;
	randStr[i] = last_c;
	randStr[i + 1] = '\0';
	printf("%s", randStr);

	return (0);
}
