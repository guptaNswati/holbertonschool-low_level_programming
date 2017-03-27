#include "binary_trees.h"

/**
* heapify - restores the max heap property of max binary heap tree
* @root: pointer to new node
* Return: nothing
**/
void heapify(heap_t *new_node)
{
	int tmp;

	if (!new_node->parent)
		return;
	if (new_node->parent->n < new_node->n)
	{
		tmp = new_node->n;
		new_node->n = new_node->parent->n;
		new_node->parent->n = tmp;
		heapify(new_node->parent);
	}
}

/**
* heap_insert - inserts a value in Max Binary Heap
* @tree: double pointer to the root node of the Heap to insert the value in
* @value: value to store in the node to be inserted
* Return: a pointer to the created node, or NULL on failure
**/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = (heap_t*)binary_tree_node(*root, value);

	if (!*root)
		*root = new_node;
	else if (!(*root)->left)
		(*root)->left = new_node;
	else if (!(*root)->right)
		(*root)->right = new_node;
	else if (!(*root)->left->left || !(*root)->left->right)
		new_node = heap_insert(&(*root)->left, value);
	else
		new_node = heap_insert(&(*root)->right, value);
	heapify(new_node);
	return (new_node);
}
