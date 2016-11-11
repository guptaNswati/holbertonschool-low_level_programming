#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
	int result, num, i, j;

	if (argc < 3 || argc > 3)
	{
		printf("Error\n");
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
				printf("Error\n");
				exit (98);
			}
		}
		result *= num;
	}
	printf("%d\n", result);
	return (0);
}
