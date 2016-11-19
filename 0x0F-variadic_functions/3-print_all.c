#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "variadic_functions.h"
/**
* print_all - prints anything
* @format: list of types of arguments passed to the function
* Return: nothing, prints anything
**/
void print_all(const char * const format, ...)
{
	va_list paramsList;
	char *str;
	int k;

	if (format == NULL || *format == '\0')
		;
	else
	{
		va_start(paramsList, format);
		k = 0;
		while (format[k] != '\0')
		{
			switch (format[k])
			{
			case 'c':
				printf("%c", va_arg(paramsList, int));
				k++;
				break;
			case 'i':
				printf("%d", va_arg(paramsList, int));
				k++;
				break;
			case 'f':
				printf("%f", va_arg(paramsList, double));
				k++;
				break;
			case 's':
				str = va_arg(paramsList, char *);
				if (str != NULL || *str != '\0')
					printf("%s", str);
				else
					printf("(nil)");
				k++;
				break;
			default:
				k++;
			}
			if (format[k] != '\0' &&
			    (format[k] == 'c' || format[k] == 'i' ||
			     format[k] == 'f' || format[k]  == 's'))
				printf(", ");
		}
		printf("\n");
		va_end(paramsList);
	}
}
