#include "sort.h"

/**
* selection_sort - sorts an array of integers in ascending order
* @array: array to be sorted
* @size: size of the array
* Return: nothing
**/
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, indx;

	if (!array || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		tmp = array[i];
		indx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < tmp)
			{
				tmp = array[j];
				indx = j;
			}
		}
		array[indx] = array[i];
		array[i] = tmp;
		print_array(array, size);
	}
}
