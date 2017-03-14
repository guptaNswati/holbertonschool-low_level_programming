#include <math.h>
#include "binary_trees.h"

/**
* max - compares two ints to return the maximum of two
* @left: first number
* @righy: second number
* Return: max of two
**/
int max(int left, int right)
{
	if (left >= right)
		return (left);
	return (right);
}

/**
* count_nodes - counts total number of nodes of the tree
* @tree: pointer to root node of tree
* Return: total number of nodes or 0
**/
int count_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
* count_height - calculates height of a given binary tree, considering root
* at height 1.
* @tree: pointer to the root node of the tree to check
* Return: height of tree or 0
**/
int count_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + max(count_height(tree->left), count_height(tree->right)));
}

/**
* binary_tree_is_perfect - checks if a binary tree is perfect
* @tree:  pointer to the root node of the tree to check
* Return: 1 if tree is perfect and 0 if not or tree is NULL
**/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int total_nodes, height;

	height = count_height(tree);
	total_nodes = count_nodes(tree);
	printf("[result] %d\n", total_nodes);
	printf("[level] %d\n", height);
	/* perfect tree will have 2^level+1 - 1 nodes*/
	if (total_nodes == pow(2, height) - 1)
		return (1);
	return (0);
}
