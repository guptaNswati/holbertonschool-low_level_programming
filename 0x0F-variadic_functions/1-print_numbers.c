#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
* print_numbers - prints numbers, followed by a new line
* @separator: string to be printed between numbers
* @n: number of arguements
* Return: nothing, prints number if separator is not NULL
**/
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list paramsList;
	unsigned int i;

	if (n == 0)
	{
		printf("\n");
		return;
	}
	va_start(paramsList, n);
	for (i = 0; i < n - 1; i++)
	{
		printf("%d", va_arg(paramsList, unsigned int));
		if (separator != NULL)
			printf("%s", separator);
	}
	printf("%d\n", va_arg(paramsList, unsigned int));
	va_end(paramsList);
}
