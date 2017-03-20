#include "binary_trees.h"

/**
* depth - finds the depth of given node
* @node: pointer to given node
* Return: depth of node or 0 if node is NULL
**/
int depth(const binary_tree_t *node)
{
	const binary_tree_t *tmp = node;
	int depth = -1;

	while (tmp)
	{
		++depth;
		tmp = tmp->parent;
	}
	return (depth);
}
/**
* binary_trees_ancestor - finds the lowest common ancestor of two nodes
* @first: a pointer to the first node
* @second: a pointer to the second node
* Return: pointer to the lowest common ancestor node of the two given nodes
* or NULL
**/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	int diff;
	const binary_tree_t *tmp;

	/* compare the depths of both nodes */
	diff = depth(first) - depth(second);
	/* swap the deeper node with least deep node*/
	if (diff < 0)
	{
		tmp = second;
		second = first;
		first = tmp;
		diff *= -1;
	}
	/* bring it at same level as the other node */
	while (diff--)
		first = first->parent;
	/* check if they have same parent */
	while (first && second)
	{
		if (first->n == second->n)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return (NULL);
}
