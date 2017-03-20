#include "binary_trees.h"
#include <limits.h>

/**
* find_max - finds the maximum number among two given numbers
* @left: fisrt number
* @right: second number
* Return: max of two numbers
**/
int find_max(size_t left, size_t right)
{
	if (left >= right)
		return (left);
	return (right);
}

/**
* find_height - finds the height of a binary tree
* @tree: pointer to the root node of the tree to check
* Return: height of tree
**/
int find_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + find_max(find_height(tree->left), find_height(tree->right)));
}

/**
* is_balanced - checks if a given bst is balanced or not
* @tree: pointer to the root node of the tree to check
* Return: 1 if balanced, 0 otherwise
**/
int is_balanced(const binary_tree_t *tree)
{
	int result;

	if (!tree)
		return (1);
	result = find_height(tree->left) - find_height(tree->right);
	if (result >= -1 && result <= 1)
		return (1);
	return (is_balanced(tree->left) && is_balanced(tree->right));
}

/**
* isbst - check if a given tree is valid binary search tree or not
* @tree: pointer root node of the tree to check
* Return: 1 if bst, 0 otherwise
**/
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (is_bst(tree->left, min, tree->n - 1) &&
		is_bst(tree->right, tree->n + 1, max));
}

/**
* binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
* @tree: pointer to the root node of the tree to check
* Return: 1 if tree is a valid AVL Tree, and 0 if not or tree is NULL
**/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int result;

	if (tree)
	{
		if (is_bst(tree, INT_MIN, INT_MAX) && is_balanced(tree))
			return (1);
/*		printf("[height of left-tree] %d\n", find_height(tree->left));
		printf("[height of rigth-tree] %d\n", find_height(tree->right));
		result = find_height(tree->left) - find_height(tree->right);
		printf("is bst %d\n", isbst(tree, INT_MIN, INT_MAX));
		printf("result %d\n", result); */
	}
	return (0);
}
