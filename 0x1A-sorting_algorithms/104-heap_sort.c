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
* heapify - brings the largest node of a given subtree to root.
* @array: array to be heapify
* @size: size of array
* @i: root node
**/
void heapify(int *array, size_t size, size_t i)
{
	size_t largest, left, right;

	largest = i;
	left = 2 * i + 1;
	right = 2 * i + 2;
	if (left < size && array[left] > array[largest])
		largest = left;
	if (right < size && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, size, largest);
	}
}

/**
* heap_sort - sorts an array of integers in ascending order using
* sift-down Heap sort
* @array: array to be sorted
* @size: size of the array
* Return: nothing
**/
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (!array || size < 2)
		return;
	for (i = (size - 2) / 2 + 1; i > 0; i--)
		heapify(array, size, i - 1);
	for (i = size; i > 0; i--)
	{
		swap(&array[0], &array[i - 1]);
		print_array(array, size);
		heapify(array, i - 1, 0);
 	}
}
