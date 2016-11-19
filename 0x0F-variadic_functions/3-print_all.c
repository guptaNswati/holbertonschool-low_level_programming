#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

#define TYPE(b) ("%"#b)

/**
* print_all - prints anything
* @format: list of types of arguments passed to the function
* Return: nothing, prints anything
**/
void print_all(const char * const format, ...)
{
	va_list paramsList;
	char *str, t;
	int k, j;
	struct type
	{
		char a;
		char *ttype;
	};
	struct type tarray[4];

	tarray[0].a = 'c';
	tarray[0].ttype = "int";
	tarray[1].a = 'i';
	tarray[1].ttype = "int";
	tarray[2].a = 'f';
	tarray[2].ttype = "double";
	tarray[3].a = 's';
	tarray[3].ttype = "char *";
	va_start(paramsList, format);
	k = 0;
	while (format[k] != '\0')
	{
		t = format[k];
		j = 0;
		while (j < 4)
		{
			if (t == tarray[j].a)
			{
				str = va_arg(paramsList, tarray[j].ttype);
				printf(TYPE(t), str);
				break;
			}
			j++;
		}
		k++;
	}
	printf("\n");
	va_end(paramsList);
}
