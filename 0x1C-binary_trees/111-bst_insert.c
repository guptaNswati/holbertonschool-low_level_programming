#include "binary_trees.h"

/**
* insert_bst_helper - finds the right spot in bst for new_node recursively
* @tree: double pointer to the root node of the BST to insert the value in
* @new_node: node to be added to the tree
* Return: pointer to new node or NULL
**/
bst_t *insert_bst_helper(bst_t **tree, bst_t *new_node)
{
	if (!*tree)
	{
		*tree = new_node;
		return (new_node);
	}
	if ((*tree)->n == new_node->n)
	{
		free(new_node);
		new_node = NULL;
		return (new_node);
	}
	if (new_node->n < (*tree)->n)
	{
		if (!(*tree)->left)
		{
			(*tree)->left = new_node;
			new_node->parent = *tree;
			return (new_node);
		}
		return (insert_bst_helper(&(*tree)->left, new_node));
	}
	if (new_node->n > (*tree)->n)
	{
		if (!(*tree)->right)
		{
			(*tree)->right = new_node;
			new_node->parent = *tree;
			return (new_node);
		}
		return (insert_bst_helper(&(*tree)->right, new_node));
	}
}

/**
* bst_insert - inserts a value in a Binary Search Tree
* @tree: double pointer to the root node of the BST to insert the value in
* @value: value to store in the node to be inserted
* Return: pointer to the created node, or NULL on failure
**/
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node;

	new_node = malloc(sizeof(bst_t));
	if (!new_node)
		return (NULL);
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = NULL;
	return (insert_bst_helper(tree, new_node));
}
