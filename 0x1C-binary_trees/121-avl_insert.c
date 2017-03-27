#include "binary_trees.h"

/**
* avl_insert - inserts a value in an AVL Tree
* @tree: double pointer to the root node of the AVL tree to insert the value in
* @value: value to store in the node to be inserted
* Return: pointer to the created node, or NULL on failure
**/
avl_t *avl_insert(avl_t **tree, int value)
{
	(avl_t *)binary_tree_node(*tree, value);
	
}
