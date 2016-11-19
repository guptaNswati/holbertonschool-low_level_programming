#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
* print_strings - prints strings, followed by a new line
* @separator: string to be printed between strings
* @n: number of arguements
* Return: nothing, prints number if separator is not NULL
**/
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list paramsList;
	unsigned int i;
	char *str;

	if (n == 0)
	{
		printf("\n");
		return;
	}
	va_start(paramsList, n);
	for (i = 0; i < n - 1; i++)
	{
		str = va_arg(paramsList, char *);
		if (str == NULL)
			printf("(nil)");
		else
			printf("%s", str);
		if (separator != NULL)
			printf("%s", str);
	}
	str = va_arg(paramsList, char *);
	printf("%s\n", str);
	va_end(paramsList);
}
