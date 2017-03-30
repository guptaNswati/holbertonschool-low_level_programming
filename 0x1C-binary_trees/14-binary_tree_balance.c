#include "binary_trees.h"

/**
* get_max - returns max of two numbers
* @left: number 1
* @right: number 2
* Return: the max
**/
int get_max(int left, int right)
{
	if (left > right)
		return (left);
	return (right);
}


/**
* get_height - calculates height of root
* @tree: pointer to root node of tree to count height of
* Return: height or 0
**/
int get_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + get_max(get_height(tree->left), get_height(tree->right)));
}


/**
* binary_tree_balance - measures the balance factor of a binary tree
* @tree: pointer to the root node of the tree to measure the balance factor of
* Return: balance factor or 0
**/
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (get_height(tree->left) - get_height(tree->right));
}
