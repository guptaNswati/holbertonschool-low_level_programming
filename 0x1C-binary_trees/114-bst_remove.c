#include "binary_trees.h"


/**
* find_min - finds the minimum node of a bst
* @root: pointer to root of tree to find the node in
* Return: pointer to found node
**/
bst_t *find_min(bst_t *root)
{
	bst_t *tmp;

	while (root->left)
		root = root->left;
	tmp = root;
	root->parent = NULL;
	return (tmp);
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
	bst_t *tmp, *cur;

	if (!root)
		return (NULL);
	if (value == root->n)
	{
		/* node to be deleted has no children */
		if (!root->left && !root->right)
			tmp = root->parent;
		/* node to be deleted has 1 child */
		else if (!root->left || !root->right)
		{
			if (root->left)
				tmp = root->left;
			else
				tmp = root->right;
			if (root->parent)
			{
				if (tmp->n > root->parent->n)
					root->parent->right = tmp;
				else
					root->parent->left = tmp;
				tmp->parent = root->parent;
				tmp = root->parent;
			}
		}
		/* if node to be deleted has two children */
		else if (root->left && root->right)
		{
			/* find min of right subtree */
			tmp = find_min(root->right);
			if (root->parent)
			{
				cur = root->parent;
				if (root->n == cur->left->n)
					cur->left = tmp;
				else
					cur->right = tmp;
				tmp->parent = cur;
				tmp = cur;
			}
			tmp->left = root->left;
			root->left->parent = tmp;
			tmp->right = root->right;
			root->right->parent = tmp;
		}
		free(root);
		root = NULL;
		return (tmp);
	}
	if (value < root->left->n)
		return (bst_remove(root->left, value));
	else
		return (bst_remove(root->right, value));
}
