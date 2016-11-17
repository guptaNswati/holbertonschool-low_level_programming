#include <stdlib.h>
#include "function_pointers.h"

/**
* array_iterator - function that executes a function on each element of an array
* @array: pointer to array to be iterated
* @size: number of elements in array
* @action: pointer to function
**/
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array == NULL || size == 0)
		;
	else
	{
		for (i = 0; i < size; i++)
			action(array[i]);
	}
}
