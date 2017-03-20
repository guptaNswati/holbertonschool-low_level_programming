#include "binary_trees.h"

/**
* binary_tree_rotate_left - performs a left-rotation on a binary tree
* @tree: pointer to the root node of the tree to rotate
* Return: pointer to the new root node of the tree once rotated
**/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp;

	if (!tree)
		return (NULL);
	if (!tree->left && !tree->right)
		return (tree);
	if (!tree->right)
		return (tree);
	tmp = tree->right;
	if (tmp->left)
	{
		tree->right = tmp->left;
		tmp->left->parent = tree;
	}
	tmp->left = tree;
	tree->parent = tmp;
	tree = tmp;
	return (tmp);
}
