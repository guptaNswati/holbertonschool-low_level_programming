#ifndef B_TREES
#define B_TREES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/**
* struct binary_tree_s - Binary tree node
*
* @n: Integer stored in the node
* @parent: Pointer to the parent node
* @left: Pointer to the left child node
* @right: Pointer to the right child node
*/
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

/**
* struct node_list - Linkedlist node
*
* @n: Integer stored in the node
* @next: Pointer to next node in the list
**/
typedef struct node_list
{
	int n;
	struct node_list *next;
} node_l;

/**
* struct list_of_list - Linkedlist of linkedlist node
*
* @node: Pointer to the node of likendlist
* @next: Pointer to next node of list pointing to a linkedlist
**/
typedef struct list_of_list
{
	node_l *node;
	struct list_of_list *next;
} list_l;

/**
* queue - struct for level order traversal
* @node: pointer to binary_tree_t node
* @next: pointer to next queue element
**/
typedef struct queue
{
	binary_tree_t *node;
	struct queue *next;
} queue;

void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *node);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);

int depth(const binary_tree_t *node);
/**
* binary_trees_ancestor - finds the lowest common ancestor of two nodes
* @first: a pointer to the first node
* @second: a pointer to the second node
* Return: pointer to the lowest common ancestor node of the two given nodes
* or NULL
**/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second);

node_l *add_end(node_l **head, int n);
list_l *add_tolist(list_l **head, node_l *node);
int list_size(list_l **head_l);
node_l *get_node(list_l **head_l, int level);
/**
* level_order_traversal - a utility function to traverse a binary tree
* using level-order traversal
* @tree: pointer to the root node of the tree to traverse
* @head_l: pointer to pointer to head of list of list
* @level: current depth of the tree
* Return: nothing
**/
void level_order_traversal(const binary_tree_t *tree, list_l **head_l,
			   int level);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

int check_node_index(size_t size, size_t index, const binary_tree_t *tree);
int binary_tree_is_complete(const binary_tree_t *tree);

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

int binary_tree_is_bst(const binary_tree_t *tree);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *bst_remove(bst_t *root, int value);

int find_max(size_t left, size_t right);
int is_balanced(const binary_tree_t *tree);
int is_balanced(const binary_tree_t *tree);
int is_bst(const binary_tree_t *tree, int min, int max);
int binary_tree_is_avl(const binary_tree_t *tree);

avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);
avl_t *avl_remove(avl_t *root, int value);
avl_t *sorted_array_to_avl(int *array, size_t size);

int binary_tree_is_heap(const binary_tree_t *tree);
heap_t *heap_insert(heap_t **root, int value);
heap_t *array_to_heap(int *array, size_t size);
int heap_extract(heap_t **root);
int *heap_to_sorted_array(heap_t *heap, size_t *size);


#endif
