#include "binary_trees.h"

void change_parent(bst_t *parent, bst_t *node, bst_t *to_rmv)
{
	if (node)
		node->parent = parent;
	if (parent)
	{
		if (to_rmv == parent->left)
			parent->left = node;
		else
			parent->right = node;
	}
	free(to_rmv);
	to_rmv = NULL;
}

/**
* find_min - finds the minimum node of a bst
* @root: pointer to root of tree to find the node in
* Return: pointer to found node
**/
int find_min(bst_t *root)
{
	int tmp;
	bst_t *cur = root;

	while (cur->left)
		cur = cur->left;
	tmp = cur->n;
	change_parent(cur->parent, cur->right, cur);
	return (tmp);
}

/**
* search_bst - searches for a node in bst
* @root: pointer to root of tree
* @value: value to search for
* Return: pointer to found node or null
**/
bst_t *search_bst(bst_t *root, int value)
{
	if (!root)
		return (NULL);
	if (value == root->n)
		return ((bst_t *)root);
	if (value < root->n)
		return (search_bst(root->left, value));
	return (search_bst(root->right, value));
}


/**
* bst_remove - removes a node from a Binary Search Tree
* @root: pointer to the root node of the tree to remove a node of
* @value: the value to look for
* Return: pointer to the new root node of the tree after removing the desired
* value
**/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *to_rmv, *parent;

	if (!root)
		return (NULL);

	to_rmv = search_bst(root, value);
	parent = to_rmv->parent;
	/* if no child */
	if (!to_rmv->left && !to_rmv->right)
	{
		free(to_rmv);
		to_rmv = NULL;
		return (parent);
	}
	/* if left child */
	if (to_rmv->left)
	{
		change_parent(parent, to_rmv->left, to_rmv);
		return (parent);
 	}
	if (to_rmv->right)
	{
		change_parent(parent, to_rmv->right, to_rmv);
		return (parent);
	}
	/* if both children */
	to_rmv->n = find_min(to_rmv->right);
	return (to_rmv);
}
