#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 *\using the Bubble sort algorithm
 * @array: given array
 * @size: size of the given array
 * Return: returns nothing
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;
	int tmp, flag;

	for (i = 1; i < size; ++i)
	{
		flag = 0;
		for (j = 0; j < size - i; ++j)
		{
			if (array[j] > array[j + 1])
			{
				flag = 1;
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}
}
