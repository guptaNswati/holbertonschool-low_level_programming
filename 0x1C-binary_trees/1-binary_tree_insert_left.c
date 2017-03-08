#include "binary_trees.h"

/**
* binary_tree_insert_left - inserts a node as the left-child of another node,
* if parent already has a left-child, the new node must take its place, and
* the old left-child must be set as the left-child of the new node.
* @parent: pointer to the node to insert the left-child in
* @value: value to store in the new node
* Return: pointer to new node or null
**/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp, *cur;

	if (!parent)
		return (NULL);

	tmp = malloc(sizeof(binary_tree_t));
	if (!tmp)
		return (NULL);
	tmp->n = value;
	tmp->right = NULL;

	if (!parent->left)
	{
		parent->left = tmp;
		return (tmp);
	}
	cur = parent->left;
	parent->left = tmp;
	tmp->parent = parent;
	tmp->left = cur;
	cur->parent = tmp;
	return (tmp);
}
