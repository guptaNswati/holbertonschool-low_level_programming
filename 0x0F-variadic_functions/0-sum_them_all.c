#include <stdarg.h>
#include "variadic_functions.h"

/**
* sum_them_all - sum of all its parameters
* @n: number of arguements
* Return: sum of all parameters or 0
**/
int sum_them_all(const unsigned int n, ...)
{
	va_list paramsList;
	unsigned int i;
	int sum;

	if (n == 0)
		return (0);

	va_start(paramsList, n);
	sum = 0;
	for (i = 0; i < n; i++)
		sum += va_arg(paramsList, int);

	va_end(paramsList);

	return (sum);
}
