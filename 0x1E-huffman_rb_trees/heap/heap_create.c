#include "heap.h"

/**
* heap_create - creates a min Heap data structure
* @data_cmp: a pointer to a comparison function
* Return: a pointer to the created heap_t structure, or NULL if it fails
**/
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *min_heap;

	min_heap = malloc(sizeof(heap_t));
	if (!min_heap)
		return (NULL);
	min_heap->size = 0;
	min_heap->data_cmp = data_cmp;
	min_heap->root = NULL;
	return (min_heap);
}
