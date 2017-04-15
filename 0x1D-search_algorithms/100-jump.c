#include "search_algos.h"
#include <math.h>

/**
* jump_search - searches for a value in a sorted array of integers using the
* Jump search algorithm.
* @array: pointer to the first element of the array to search in
* @size: number of elements in array
* @value: value to search for
* Return: index of where value is located, else -1
**/
int jump_search(int *array, size_t size, int value)
{
	size_t i, jump, step;

	if (!array || size == 0)
		return (-1);

	i = 0;
	jump = 0;
	step = sqrt(size);
	while (array[jump] < value && jump < size)
	{
		printf("Value checked array[%lu] = [%d]\n", jump, array[jump]);
		i = jump;
		jump += step;
	}
	printf("Value found between indexes [%lu] and [%lu]\n", i, jump);
	/* if jump went outside the size */
	if (jump > size - 1)
		jump = size - 1;
	/* jump 1 block backwards and do linear search */
	while (i <= jump)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
