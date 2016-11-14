#include "dog.h"

/**
* init_dog - initialize a variable of type struct dog
* @d: pointer to an element of type dog
* @name: pointer to a char for name of dog
* @age: age of dog
* @owner: pointer to a char for owner of dog
* Return: nothing
**/
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	struct dog *d1;

	if (d == NULL)
		;
	else
	{
		d1 = d;
		d1->name = name;
		d1->age = age;
		d1->owner = owner;
	}
}
