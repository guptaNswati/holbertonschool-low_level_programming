#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
/**
* print_dog - prints a struct dog
* @d: pointer to an element of type dog
* Return: nothing
**/
void print_dog(struct dog *d)
{
	if (d == NULL)
		;
	else
	{
		if (d->name != NULL)
			printf("Name: %s\n", d1->name);
		else
			printf("nil\n");
		if (d->age != 0 || d1->age > 0)
			printf("Age: %.1f\n", d1->age);
		else
			printf("nil\n");
		if (d->owner != NULL)
			printf("Owner: %s\n", d1->owner);
		else
			printf("nil\n");
	}
}
