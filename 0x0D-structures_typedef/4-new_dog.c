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
	dog_t *d1;

	d1 = (dog_t *)malloc(sizeof(dog_t));
	if (d1 == NULL)
		return (NULL);

	d1->name = name;
	if (d1->name == NULL)
		return (NULL);
	d1->age = age;
	d1->owner = owner;
	if (d1->owner == NULL)
                return (NULL);

	return (d1);
}
