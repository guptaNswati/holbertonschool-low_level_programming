#include "search_algos.h"

/**
* binary_helper - search of elements using binary serach, including
* start and end.
* @array: array is a pointer to the first element of the array to search in
* @start: starting index of array
* @end: last index
* @value: value to be searched
* Return: index where value is located or else -1
**/
int binary_helper(int *array, size_t start, size_t end, int value)
{
	size_t mid, i;

	if (start > end)
		return (-1);
	printf("Searching in array: ");
	for (i = start; i < end; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
	mid = (start + end) / 2;
	if (array[mid] == value)
		return (mid);
	if (array[mid] > value)
		return (binary_helper(array, start, mid, value));
	return (binary_helper(array, mid + 1, end, value));
}

/**
* advanced_binary - searches for a repeating value in a sorted array of
* integers using binary search
* @array: array is a pointer to the first element of the array to search in
* @size: is the number of elements in array
* @value: is the value to search for
* Return: index where value is located or else -1
**/
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);
	return (binary_helper(array, 0, size - 1, value));
}
