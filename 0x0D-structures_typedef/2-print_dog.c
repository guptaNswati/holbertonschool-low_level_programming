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
	struct dog *d1;

	if (d == NULL)
		;
	else
	{
		d1 = d;

		if (d1->name != NULL)
			printf("Name: %s\n", d1->name);
		else
			printf("nil\n");
		if (d1->age != 0)
			printf("Age: %.1f\n", d1->age);
		else
                        printf("nil\n");
		if (d1->owner != NULL)
			printf("Owner: %s\n", d1->owner);
		else
                        printf("nil\n");
	}
}
