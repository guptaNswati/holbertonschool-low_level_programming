#include <stdarg.h>

#ifndef VARIADIC_FUNC
#define VARIADIC_FUNC

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);

/**
* struct type - Struct for calling the right printf for printing anything
* @a: format specifier for printf
* @ttype: pointer to function for appropriate printf()
**/
struct type
{
	char a;
	void (*ttype)(char, va_list);
};

void print_all(const char * const format, ...);

#endif
