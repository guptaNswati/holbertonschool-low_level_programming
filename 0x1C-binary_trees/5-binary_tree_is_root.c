#include "binary_trees.h"

/**
* binary_tree_is_root - checks if a node is a root
* @node: pointer to the node to check
* Return: 1 if node is a root, and 0 otherwise
**/
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (!node->parent)
		return (1);
	return (0);
}
