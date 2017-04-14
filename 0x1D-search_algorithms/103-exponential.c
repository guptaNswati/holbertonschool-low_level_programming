#include "search_algos.h"

/**
* exponential_search - searches for a value in a sorted array of integers using
* the Exponential search algorithm: find range using exponential iterations and
* do in the found range, do binary search.
* @array: is a pointer to the first element of the array to search in
* @size: is the number of elements in array
* @value: is the value to search for
* Return: index of found value or else -1
**/
int exponential_search(int *array, size_t size, int value)
{
	size_t start, mid, end, i;

	if (!array || size == 0)
		return (-1);
	/* if value at first index */
	if (array[0] == value)
	{
		printf("Value checked array[%d] = [%d]\n", 0, array[0]);
		return (0);
	}
	start = 1;
	while (start < size && array[start] <= value)
	{
		printf("Value checked array[%lu] = [%d]\n",
		       start, array[start]);
		if (array[start] == value)
			return (start);
		start *= 2;
	}
	/* do binary search on found range */
	if (start < size)
		end = start;
	else
		end = size - 1;
	start = start / 2;
	while (start <= end)
	{
		/* print sub array to be searched */
		printf("Searching in array: ");
		for (i = start; i < end; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		mid = (start + end) / 2;
		if (array[mid] == value)
			return (mid);
		if (array[mid] > value)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return (-1);

}
