#include "binary_trees.h"

/**
* binary_tree_rotate_right - performs a right-rotation on a binary tree
* @tree: pointer to the root node of the tree to rotate
* Return: pointer to the new root node of the tree once rotated
**/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp, *tree_p, *right_node;
	int for_right = 0;

	if (!tree)
		return (NULL);
	if (!tree->left && !tree->right)
		return (tree);
	if (!tree->left)
		return (tree);
	/* save ref to parent */
	tree_p = tree->parent;
	/* to check if current node is in left subtree or right tree */
	if (tree_p && tree_p->right == tree)
		for_right = 1;
	/* save the ref to the node to be rotated */
	tmp = tree->left;
	/* save ref to tmp nodes right child */
	right_node = tmp->right;
	tree->left = right_node;
	if (right_node)
		right_node->parent = tree;
	tmp->right = tree;
	tree->parent = tmp;
	if (tree_p)
	{
		if (for_right)
			tree_p->right = tmp;
		else
			tree_p->left = tmp;
	}
	tmp->parent = tree_p;
	return (tmp);
}
