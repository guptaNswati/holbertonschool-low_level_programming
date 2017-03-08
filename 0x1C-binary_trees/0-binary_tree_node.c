#include "binary_trees.h"

/**
* binary_tree_node - creates a binary tree node
* @parent: pointer to root of tree
* @value: value of the node
* Return: pointer to new node or NULL
**/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp;

	tmp = malloc(sizeof(binary_tree_t));
	if (tmp == NULL)
		return (NULL);
	tmp->n = value;
	tmp->left = NULL;
	tmp->right = NULL;

	if (!parent)
	{
		parent = tmp;
		return (tmp);
	}
	/* go left */
	if (value < parent->n && !parent->left)
	{
		parent->left = tmp;
		tmp->parent = parent;
		return (tmp);
	}
	/* go right */
	if (value > parent->n && !parent->right)
	{
		parent->right = tmp;
		tmp->parent = parent;
		return (tmp);
	}
	/* recursively find the position for new node in left subtree */
	return (binary_tree_node(parent->left, value));
	return (binary_tree_node(parent->right, value));
}
