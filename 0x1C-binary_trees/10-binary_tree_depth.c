#include "binary_trees.h"

/**
* binary_tree_depth - measures the depth of a node in a binary tree
* @node: pointer to node to measure the depth of
* Return: depth of tree or 0 is node is NULL
**/
size_t binary_tree_depth(const binary_tree_t *node)
{
	size_t left, right;

	if (!node)
		return (0);
	if (!node->parent)
		return (0);
	left = binary_tree_depth(node->left);
	right = binary_tree_depth(node->right);
	if (left > right)
		return (1 + right);
	else
		return (1 + left);
}
