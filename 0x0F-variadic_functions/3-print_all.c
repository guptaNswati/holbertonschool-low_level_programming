#include <stdio.h>
#include <stdlib.h>
#include "variadic_functions.h"

/**
* printC_I - prints a char or an int
* @b: format specifier for printf
* @param: arguement to be printed
* Return: nothing, but print a char or an int
**/
void printC_I(char *b, va_list param)
{
	printf(b, va_arg(param, int));
}

/**
* printFlt - prints a float
* @b: format specifier for printf
* @param: arguement to be printed
* Return: nothing, but print a float
**/
void printFlt(char *b, va_list param)
{
	printf(b, va_arg(param, double));
}

/**
* printStr - prints a string
* @b: format specifier
* @param: string to be printed
* Return: nothing, but prints a string if not null, else (nil)
**/
void printStr(char *b, va_list param)
{
	char *s;

	s = va_arg(param, char *);
	if (s == NULL)
		s = "(nil)";
	printf(b, s);
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
	char *sep;

	type tarray[] = {{'c', "%c", printC_I},
			 {'i', "%d", printC_I},
			 {'f', "%f", printFlt},
			 {'s', "%s", printStr},
	};
	va_start(paramsList, format);
	k = 0;
	sep = "";
	while (format != NULL && format[k] != '\0')
	{
		j = 0;
		while (j < 4)
		{
			if (format[k] == tarray[j].a)
			{
				printf("%s", sep);
				tarray[j].ttype(tarray[j].f, paramsList);
				sep = ", ";
			}
			j++;
		}
		k++;
	}
	va_end(paramsList);
	printf("\n");
}
