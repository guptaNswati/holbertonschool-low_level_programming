#include "binary_trees.h"

/**
* binary_tree_insert_right - inserts a node as the right-child of another node,
* if parent already has a right-child, the new node must take its place, and
* the old right-child must be set as the right-child of the new node.
* @parent: pointer to the node to insert the right-child in
* @value: value to store in the new node
* Return: pointer to new node or null
**/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp, *cur;

	if (!parent)
		return (NULL);

	tmp = malloc(sizeof(binary_tree_t));
	if (!tmp)
		return (NULL);
	tmp->n = value;
	tmp->left = NULL;

	if (!parent->right)
	{
		parent->right = tmp;
		return (tmp);
	}
	cur = parent->right;
	parent->right = tmp;
	tmp->parent = parent;
	tmp->right = cur;
	cur->parent = tmp;
	return (tmp);
}
