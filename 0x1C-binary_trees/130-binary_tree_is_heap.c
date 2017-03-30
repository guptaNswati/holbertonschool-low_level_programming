#include "binary_trees.h"

/**
* size_of_bt - calculates the size of the binary tree
* @tree: pointer to root node
* Return: size of the tree or 0
**/
size_t size_of_bt(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + size_of_bt(tree->left) + size_of_bt(tree->right));
}

/**
* is_complete - checks if a given tree is complete or not
* @size: size of the tree
* @index: current nodes index
* @tree: pointer to root of tree
* Return: 1 if tree is complete, else 0
**/
int is_complete(size_t size, size_t index, const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	if (index >= size)
		return (0);
	return (is_complete(size, 2 * index + 1, tree->left) &&
		is_complete(size, 2 * index + 2, tree->right));
}

/**
* is_heap - checks if a given tree is satisfies max heap property
* @tree: pointer to root node of tree
* Return: 1 if heap, else 0
**/
int is_heap(const binary_tree_t *tree)
{
	if (!tree->left && !tree->right)
		return (1);
	if (!tree->right && tree->n > tree->left->n)
		return (1);
	if (tree->n > tree->left->n && tree->n > tree->right->n)
		return (is_heap(tree->left) && is_heap(tree->right));
	return (0);
}

/**
* binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
* max heap property: complete, value at root is maximum and true for all nodes
* @tree: pointer to the root node of the tree to check
* Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
**/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = size_of_bt(tree);
	if (is_complete(size, 0, tree) && is_heap(tree))
		return (1);
	return (0);
}
