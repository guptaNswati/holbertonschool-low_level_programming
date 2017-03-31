#include "binary_trees.h"

/**
* count_heap - counts number of nodes in a max heap
* @heap: pointer to heap
* Return: count of nodes or 0
**/
size_t count_heap(heap_t *heap)
{
	if (!heap)
		return (0);
	return (1 + count_heap(heap->left) + count_heap(heap->right));
}

/**
* heap_to_sorted_array - converts a Binary Max Heap to a sorted array
* @heap: pointer to the root node of the heap to convert
* @size: address to store the size of the array
* Return: pointer to sorted array
**/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *arr;
	size_t i;

	if (!heap)
		return (NULL);

	*size = count_heap(heap);
	arr = malloc(sizeof(int) * (*size));
	if (!arr)
		return (NULL);
	for (i = 0; i < (*size); i++)
		arr[i] = heap_extract(&heap);
	return (arr);
}
