#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	avl_t *root;
	avl_t *node;

	root = NULL;
	node = NULL;
	node = avl_insert(&root, 98);
	printf("Inserted: %d\n", node->n);
	binary_tree_print(root);
	node = avl_insert(&root, 112);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);
	node = avl_insert(&root, 202);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);
	node = avl_insert(&root, 360);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);
	node = avl_insert(&root, 428);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);
	node = avl_insert(&root, 556);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);
	node = avl_insert(&root, 612);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);
	node = avl_insert(&root, 750);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);
	node = avl_insert(&root, 812);
        printf("\nInserted: %d\n", node->n);
        binary_tree_print(root);
	node = avl_insert(&root, 912);
        printf("\nInserted: %d\n", node->n);
        binary_tree_print(root);
	node = avl_insert(&root, 932);
        printf("\nInserted: %d\n", node->n);
        binary_tree_print(root);
	return (0);
}
