#include "binary_trees.h"

/**
* find_min - finds the minimum node of a bst
* @root: pointer to root of tree to find the node in
* Return: pointer to found node
**/
bst_t *find_min(bst_t *root)
{
	bst_t *cur = root;

	while (cur->left)
		cur = cur->left;
	return (cur);
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
	bst_t *tmp;

	if (!root)
		return (NULL);
	/* search in left tree */
	if (root->n > value)
		root->left = bst_remove(root->left, value);
	/* search in right tree */
	else if (root->n < value)
		root->right = bst_remove(root->right, value);
	/* this is the node to delete */
	else
	{
		/* no child or only 1 child */
		if (!root->left)
		{
			tmp = root->right;
			free(root);
			return (tmp);
		}
		else if (!root->right)
		{
			tmp = root->left;
			free(root);
			return (tmp);
		}
		/* two children, get min of right tree */
		tmp = find_min(root->right);
		root->n = tmp->n;
		root->right = bst_remove(root->right, tmp->n);
	}
	return (root);
}
