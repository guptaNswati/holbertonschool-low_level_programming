#include "heap.h"

/**
* heap_insert - inserts a value in a Min Binary Heap
* @heap: pointer to the heap in which the node has to be inserted
* @data: pointer containing the data to store in the new node
* Return: pointer to the created node containing data, or NULL if it fails
**/
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *node;

	if (!heap)
		return (NULL);

	node = binary_tree_node(heap->root, data);
	if (!node)
		return (NULL);
	heap->size += 1;
	return (node);
}
