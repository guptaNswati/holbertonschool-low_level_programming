#include "function_pointers.h"
/**
* print_name - prints a name
* @name: pointer to char
* @f: pointer to function that returns nothing, but prints a name
**/
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
