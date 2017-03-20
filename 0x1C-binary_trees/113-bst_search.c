#include "binary_trees.h"

/**
* bst_search - searches for a value in a Binary Search Tree
* @tree: pointer to the root node of the BST to search
* @value:  value to look for
* Return: a pointer to the node containing a value equals to value or NULL
* if not found or tree is NULL
**/
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (value == tree->n)
		return ((bst_t *)tree);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
}
