#include "binary_trees.h"


/**
* get_height - calculates height of root
* @tree: pointer to root node of tree to count height of
* Return: height or 0
**/
int get_height(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	left = get_height(tree->left);
	right = get_height(tree->right);
	if (left > right)
		return (left + 1);
	else
		return (right + 1);

}


/**
* binary_tree_balance - measures the balance factor of a binary tree
* @tree: pointer to the root node of the tree to measure the balance factor of
* Return: balance factor or 0
**/
int binary_tree_balance(const binary_tree_t *tree)
{
	return (get_height(tree->left) - get_height(tree->right));
}
