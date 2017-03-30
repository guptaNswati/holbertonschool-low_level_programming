#include "binary_trees.h"

/**
* binary_tree_depth - measures the depth of a node in a binary tree
* @node: pointer to node to measure the depth of
* Return: depth of tree or 0 is node is NULL
**/
size_t binary_tree_depth(const binary_tree_t *node)
{
	if (node && node->parent)
		return (1 + binary_tree_depth(node->parent));
	return (0);
}
