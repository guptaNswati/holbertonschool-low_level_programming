#include "sort.h"

/**
* swap - function to swap array values
* @indx_1: index 1
* @indx_2: index 2
* Return: nothing
**/
void swap(int *indx_1, int *indx_2)
{
	int tmp;

	tmp = *(indx_1);
	*(indx_1) = *(indx_2);
	*(indx_2) = tmp;
}

/**
* hoarePartition - hoare's pivot partition algorithm
* @array: array to be partitioned
* @start: start index
* @end: end index
* @size: size of the array
* Return: pivot value
**/
int hoarePartition(int *array, int start, int end, size_t size)
{
	int pivot, i, j;

	pivot = array[end];
	i = start - 1;
	j = end + 1;
	while (1)
	{
		do
			i++;
		while (array[i] < pivot);

		do
			j--;
		while (array[j] > pivot);

		if (i >= j)
			return (j);
		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
* quick_sort_helper - quick sort helper function
* @array: array to be sorted
* @start: start index
* @end: end index
* @size: size of the array
* Return: nothing
**/
void quick_sort_helper(int *array, int start, int end, size_t size)
{
	int partition;

	if (start < end)
	{
		partition = hoarePartition(array, start, end, size);
		quick_sort_helper(array, start, partition, size);
		quick_sort_helper(array, partition + 1, end, size);
	}
}

/**
* quick_sort - sorts an array of integers in ascending order using the Quick
* sort algorithm with Hoare partition scheme. Also pivot should always be the
* last element of the partition being sorted.
* @array: array of ints to be sorted
* @size: size of given array
* Return: nothing, print the array each time two elements are swapped
**/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}
