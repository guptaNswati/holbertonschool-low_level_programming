#include "binary_trees.h"

/**
* binary_tree_rotate_left - performs a left-rotation on a binary tree
* @tree: pointer to the root node of the tree to rotate
* Return: pointer to the new root node of the tree once rotated
**/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp, *tree_p, *left_node;
	int for_left = 0;

	if (!tree)
		return (NULL);
	if (!tree->left && !tree->right)
		return (tree);
	if (!tree->right)
		return (tree);
	/* save ref to parent */
	tree_p = tree->parent;
	/* to check if current node is in left subtree or right tree */
	if (tree_p && tree_p->left->n == tree->n)
		for_left = 1;
	/* save the ref to the node to be rotated */
	tmp = tree->right;
	/* save ref to current nodes left child */
	left_node = tmp->left;
	tree->right = left_node;
	if (left_node)
 		left_node->parent = tree;
	tmp->left = tree;
	tree->parent = tmp;
	if (tree_p)
	{
		if (for_left)
			tree_p->left = tmp;
		else
			tree_p->right = tmp;
	}
	tmp->parent = tree_p;
	return (tmp);
}
