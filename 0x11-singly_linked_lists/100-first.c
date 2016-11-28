#include <stdio.h>

/**
* be4main - function that prints a string before main is executed,
* keyword (__attribute__) allows to specify special attributes when making
* a declaration, followed by attribute specification inside double parentheses,
* here, the constructor attribute causes the function to be called
* automatically before execution enters main ()
* refer https://gcc.gnu.org/onlinedocs/gcc-4.3.0/gcc/Function-Attributes.html
**/
void __attribute__((constructor)) be4main()
{
	printf("You're beat! and yet, you must allow,\n"
	       "I bore my house upon my back!\n");
}
