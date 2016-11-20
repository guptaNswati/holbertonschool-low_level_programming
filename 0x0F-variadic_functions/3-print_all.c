#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "variadic_functions.h"

/**
* printC_I - prints a char or an int
* @b: format specifier for printf
* @param: arguement to be printed
* Return: nothing, but print a char or an int
**/
void printC_I(char b, va_list param)
{
	if (b == 'c')
		printf("%c", va_arg(param, int));
	else
		printf("%d", va_arg(param, int));
}

/**
* printFlt - prints a float
* @b: format specifier for printf
* @param: arguement to be printed
* Return: nothing, but print a float
**/
void printFlt(char b, va_list param)
{
	/* double guard */
	if (b == 'f')
		printf("%f", va_arg(param, double));
}

/**
* printStr - prints a string
* @b: format specifier
* @param: string to be printed
* Return: nothing, but prints a string if not null, else (nil)
**/
void printStr(char b, va_list param)
{
	char *s;

	if (b == 's')
	{
		s = va_arg(param, char *);

		if (s != NULL)
			printf("%s", s);
		else
			printf("(nil)");
	}
}

/**
* print_all - prints anything
* @format: list of types of arguments passed to the function
* Return: nothing, prints anything
**/
void print_all(const char * const format, ...)
{
	va_list paramsList;
	int k, j;

	type tarray[] = {{'c', printC_I},
				{'i', printC_I},
				{'f', printFlt},
				{'s', printStr},
	};
	va_start(paramsList, format);
	k = 0;
	while (format[k] != '\0')
	{
		j = 0;
		while (j < 4)
		{
			if (format[k] == tarray[j].a)
			{
				tarray[j].ttype(tarray[j].a, paramsList);
				if (format[k + 1] != '\0')
					printf(", ");
				break;
			}
			j++;
		}
		k++;
	}
	printf("\n");
	va_end(paramsList);
}
