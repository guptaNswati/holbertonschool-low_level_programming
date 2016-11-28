#include <stdio.h>

/**
* __attribute__ - this keyword allows to specify special attributes when making
* a declaration, followed by attribute specification inside double parentheses.
* refer https://gcc.gnu.org/onlinedocs/gcc-4.3.0/gcc/Function-Attributes.html
* Here, the constructor attribute causes the function to be called
* automatically before execution enters main ()
* be4main - function that prints a string before main is executed
**/
void __attribute__((constructor)) be4main()
{
	printf("You're beat! and yet, you must allow,\n"
	       "I bore my house upon my back!\n");
}
