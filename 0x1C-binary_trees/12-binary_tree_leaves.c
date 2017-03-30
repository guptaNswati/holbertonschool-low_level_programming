#include "binary_trees.h"

/**
* binary_tree_leaves - counts the leaves in a binary tree
* @tree: a pointer to the root node of the tree to count the leaves in
* Return: count of leaves or 0 if NULL
**/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	return (binary_tree_leaves(tree->left) +
	       binary_tree_leaves(tree->right));
}
