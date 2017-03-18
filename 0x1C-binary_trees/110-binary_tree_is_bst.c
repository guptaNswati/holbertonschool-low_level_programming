#include "binary_trees.h"
#include <limits.h>

/**
* is_bst_helper - checks if a given nodes value is between  min and max
* @tree: pointer to tree to check
* @min: minimum value a node can have
* @max: maximum value a node can have
* Return: 1 if bst else 0
**/
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (is_bst_helper(tree->left, min, tree->n - 1) &&
		is_bst_helper(tree->right, tree->n + 1, max));
}

/**
* binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
* @tree: pointer to tree to check
* Return: 1 if bst and 0 if not or NULL
**/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
