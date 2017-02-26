#include "sort.h"

/**
* selection_sort - sorts an array of integers in ascending order
* @array: array to be sorted
* @size: size of the array
* Return: nothing
**/
void selection_sort(int *array, size_t size)
{
	size_t i, j, indx;
	int tmp;

	if (!array || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		indx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[indx])
				indx = j;
		}
		if (i != indx)
		{
			tmp = array[i];
			array[i] = array[indx];
			array[indx] = tmp;
			print_array(array, size);
		}
	}
}
