#include "dog.h"
#include <stdlib.h>

/**
* new_dog - creates a new dog.
* @name: pointer to a char for name of dog
* @age: age of dog
* @owner: pointer to a char for owner of dog
* Return: pointer to a new dog of type dog_t
**/
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t d, *d1;

	if (name == NULL || owner == NULL)
		return (NULL);

	d1 = &d;
	d1->name = name;
	d1->age = age;
	d1->owner = owner;

	return (d1);
}
