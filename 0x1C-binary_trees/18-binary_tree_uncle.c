#include "binary_trees.h"

/**
* binary_tree_uncle - finds the uncle of a node
* @node: pointer to the node to find the uncle of
* Return: pointer to the uncle node or NULL if no uncle
**/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node)
		return (NULL);
	if (!node->parent)
		return (NULL);
	if (!node->parent->parent)
		return (NULL);
	if (node->parent->parent->left->n == node->parent->n
	    && node->parent->parent->right)
		return (node->parent->parent->right);
	if (node->parent->parent->right->n == node->parent->n
	    && node->parent->parent->left)
		return (node->parent->parent->left);
	return (NULL);
}
