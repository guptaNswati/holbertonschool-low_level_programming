#include "search_algos.h"

/**
* binary_search - searches for a value in a sorted array of integers using the
* Binary search algorithm
* @array: pointer to the first element of the array to search in
* @size: the number of elements in array
* @value: value to search for
* Return: found value or -1 otherwise
*/
int binary_search(int *array, size_t size, int value)
{
	size_t start, mid, end, i;

	if (!array || size == 0)
		return (-1);

	start = 0;
	end = size - 1;
	while (start <= end)
	{
		/* print the array searching in */
		printf("Searching in array: ");
		for (i = start; i < end; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		mid = start + ((end - start) / 2);
		if (value == array[mid])
			return (mid);
		if (value < array[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return (-1);
}
