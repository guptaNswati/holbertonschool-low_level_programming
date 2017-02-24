#include "sort.h"

/**
* shell_sort - sorts an array of integers in ascending order using shell sort
* @array: array to be sorted
* @size: size of the array to be sorted
* Return: nothing
**/
void shell_sort(int *array, size_t size)
{
	size_t j, gap, i;
	int tmp;

	if (!array || size < 2)
		return;

	gap = 1;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j; i >= gap && array[i] < array[i - gap];
			     i -= gap)
			{
				tmp = array[i];
				array[i] = array[i - gap];
				array[i - gap] = tmp;
			}
		}
		print_array(array, size);
		gap /= 3;
	}
}
