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
	size_t i, jump;

	if (!array || size == 0)
		return (-1);
	jump = 0;
	while (array[jump] <= value && jump <= size - 1)
	{
		printf("Value checked array[%lu] = [%d]\n", jump, array[jump]);
		if (array[jump] == value)
			return (jump);
		jump += sqrt(size);
	}
	/* if value is greater than last element */
	if (value > array[size - 1])
	{
		printf("Value checked array[%lu] = [%d]\n", size - 1,
		       array[size - 1]);
		return (-1);
	}
	/* jump 1 block backwards and do linear search */
	i = (jump - sqrt(size)) + 1;
	while (i <= jump)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
