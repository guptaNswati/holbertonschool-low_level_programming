#include "binary_trees.h"


/**
* change_parent - change the parent of given node and frees to_rmv
* @parent: new parent to set
* @node: node to set parent of
* @to_rmv: node to free
* Return: nothing
**/
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
	bst_t *to_rmv;

	if (!root)
		return (NULL);

	to_rmv = search_bst(root, value);
	if (!to_rmv)
		return (NULL);
	/* if no child */
	if (!to_rmv->left && !to_rmv->right)
		change_parent(to_rmv->parent, NULL, to_rmv);
	/* if no left child */
	else if (!to_rmv->left)
		change_parent(to_rmv->parent, to_rmv->right, to_rmv);
	else if (!to_rmv->right)
		change_parent(to_rmv->parent, to_rmv->left, to_rmv);
	/* if both children */
	else if (to_rmv->left && to_rmv->right)
		to_rmv->n = find_min(to_rmv->right);
	return (root);
}
