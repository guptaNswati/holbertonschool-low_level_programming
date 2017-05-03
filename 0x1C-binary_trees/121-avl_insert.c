#include "binary_trees.h"

/**
* avl_insert - inserts a value in an AVL Tree
* @tree: double pointer to the root node of the AVL tree to insert the value in
* @value: value to store in the node to be inserted
* Return: pointer to the created node, or NULL on failure
**/
avl_t *avl_insert(avl_t **tree, int value)
{
	int bal_factor;
	avl_t *new_node, *parent;

	if (!tree)
		return (NULL);
	if (!(*tree))/* insert at root */
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	if (value < (*tree)->n)/* go left */
	{
		if (!(*tree)->left)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		new_node = avl_insert(&(*tree)->left, value);
	}
	else if (value > (*tree)->n)/* go right */
	{
		if (!(*tree)->right)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		new_node = avl_insert(&(*tree)->right, value);
	}
	else/* already in tree */
		return (*tree);
	if (!new_node)
		return (NULL);
	parent = new_node->parent;/* already in tree */
	while (parent)
	{
		bal_factor = binary_tree_balance(parent);
		/* if greater than 1, tree is left skewed */
		if (bal_factor > 1)
		{
			if (value < parent->left->n)/* left-left case */
				parent = binary_tree_rotate_right(parent);
			else if (value > parent->left->n)/* left-right case */
			{
				parent->left = binary_tree_rotate_left(parent->left);
				parent = binary_tree_rotate_right(parent);
			}
		}
		if (bal_factor < -1)
		{
			if (value > parent->right->n)/* right-right case */
				parent = binary_tree_rotate_left(parent);
			else if (value < parent->right->n)/* right-left case */
			{
				parent->right = binary_tree_rotate_right(parent->right);
				parent = binary_tree_rotate_left(parent);
			}
		}
		parent = parent->parent;
	}
	return (new_node);
}
