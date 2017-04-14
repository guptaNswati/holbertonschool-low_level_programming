#include "search_algos.h"

/**
* interpolation_search - searches for a value in a sorted array of integers
* using the Interpolation search algorithm
* @array: is a pointer to the first element of the array to search in
* @size: is the number of elements in array
* @value: is the value to search for
* Return: first index of value found, else -1
**/
int interpolation_search(int *array, size_t size, int value)
{
	size_t start, partition, end;

	if (!array || size == 0)
		return (-1);
	start = 0;
	end = size - 1;
	while (start <= end) /* array[start] <= value && value <= array[end]) */
	{
		partition = start + (((double)(end - start) /
				      (array[end] - array[start])) *
				     (value - array[start]));
		if (partition > size)
		{
			printf("Value checked array[%lu] is out of range\n",
			       partition);
			return (-1);
		}
		printf("Value checked array[%lu] = [%d]\n",
		       partition, array[partition]);
		if (array[partition] == value)
			return (partition);
		if (value < array[partition])
			end = partition;
		else
			start = partition + 1;
	}
	return (-1);
}
