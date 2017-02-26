#include "sort.h"

/**
* print_sorted - prints sorted sub arrays
* @array: array to be sorted
* @start: starting index
* @end: ending index
* Return: nothing
**/
void print_sorted(int *array, int start, int end)
{
	int i;

	for (i = start; i < end - 1; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
}

/**
* merging - function that creates a aux array and merges sorted subarrays
* @array: array to be sorted
* @aux: an aux array to be used for merging
* @start: starting index
* @mid: middle index
* @end: ending index
* Return: nothing
**/
void merging(int *array, int *aux, int start, int mid, int end)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_sorted(array, start, mid);
	printf("[right]: ");
	print_sorted(array, mid, end);

	for (i = start; i < end; i++)
		aux[i] = array[i];
	j = start;
	k = mid;
	for (i = start; i < end; i++)
	{
		if (j >= mid)
			array[i] = aux[k++];
		else if (k >= end)
			array[i] = aux[j++];
		else if (aux[k] < aux[j])
			array[i] = aux[k++];
		else
			array[i] = aux[j++];
	}
	printf("[Done]: ");
	print_sorted(array, start, end);
}

/**
* merge_sort_helper - divides the array in sub arrays for merge.
* @array: array to be sorted
* @aux: an aux array to be used for merging
* @start: starting index
* @end: ending index
* Return: nothing
**/
void merge_sort_helper(int *array, int *aux, int start, int end)
{
	int mid;

	if (end - 1 <= start)
		return;
	mid = start + (end - start) / 2;
	merge_sort_helper(array, aux, start, mid);
	merge_sort_helper(array, aux, mid, end);
	merging(array, aux, start, mid, end);
}


/**
* merge_sort - sorts an array of integers using Merge sort
* @array: array to be sorted
* @size: size of the array
* Return: nothing
**/
void merge_sort(int *array, size_t size)
{
	int *aux;

	if (!array || size < 2)
		return;

	aux = malloc(sizeof(int) * size);
	if (aux == NULL)
		return;
	merge_sort_helper(array, aux, 0, size);
	free(aux);
}
