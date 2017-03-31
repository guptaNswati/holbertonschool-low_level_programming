#include "binary_trees.h"

/**
* swap - swaps two numbers
* @num1: first number
* @num2: second number
* Return: nothing
**/
void swap(int *num1, int *num2)
{
	int tmp;

	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

/**
* adding_in_end - adds a new node at the end of the queue
* @head: double pointer to head of queue
* @node: pointer to binary tree node for adding to queue
* Return: pointer to new node of queue, or NULL
**/
queue *adding_in_end(queue **head, binary_tree_t *node)
{
	queue *tmp, *cur;

	if (!node)
		return (NULL);
	tmp = malloc(sizeof(queue));
	if (!tmp)
	{
		while (*head)
		{
			cur = *head;
			*head = (*head)->next;
			free(cur);
		}
		head = NULL;
		return (NULL);
	}
	tmp->node = node;
	tmp->next = NULL;
	if (!*head)
		*head = tmp;
	else
	{
		cur = *head;
		while (cur->next)
			cur = cur->next;
		cur->next = tmp;
	}
	return (cur);
}

/**
* removing_front - removes first node of queue
* @head: double pointer to head of queue
* Return: first node
**/
binary_tree_t *removing_front(queue **head)
{
	queue *tmp;
	binary_tree_t *node;

	if (!*head)
		return (NULL);
	tmp = *head;
	*head = (*head)->next;
	node = tmp->node;
	free(tmp);
	return (node);
}

/**
* heapify_down - restores the max heap property of max binary heap tree,
* by percolate down
* @new_node: pointer to new node
* Return: pointer to new root after restoring heap property
**/
heap_t *heapify_down(heap_t *new_node)
{
	heap_t *cur = new_node;

	while (new_node)
	{
		/* either can have two nodes or left */
		if (new_node->left)
		{
			/* if right node */
			if ((new_node->right) &&
			    (new_node->right->n > new_node->left->n) &&
			    (new_node->right->n > new_node->n))
			{
				swap(&new_node->right->n, &new_node->n);
				cur = new_node->right;
				new_node = new_node->right;
				continue;
			}
			else if (new_node->left->n > new_node->n)
			{
				swap(&new_node->left->n, &new_node->n);
				cur = new_node->left;
			}
		}
		new_node = new_node->left;
	}
	return (cur);
}

/**
* heap_extract - extracts the root node of a Max Binary Heap
* root node is freed and replaced with last node
* @root: a double pointer to the root node of heap
* Return: the value stored in the root node or 0 if fails
**/
int heap_extract(heap_t **root)
{
	binary_tree_t *cur;
	int tmp;
	queue *l_queue = NULL;

	if (!root)
		return (0);
	if (!(*root))
		return (0);

	tmp = (*root)->n;

	/* create a list of nodes with level order traversal */
	adding_in_end(&l_queue, *root);
	while (l_queue)
	{
		cur = removing_front(&l_queue);
		adding_in_end(&l_queue, cur->left);
		adding_in_end(&l_queue, cur->right);
	}
	/* if root is the node to be deleted */
	if (*root == cur)
	{
		free(*root); *root = NULL;
		root = NULL;
	}
	/* swap with root node value with last nodde */
	else
	{
		(*root)->n = cur->n;
		if (cur->parent)
		{
			if (cur == cur->parent->left)
				cur->parent->left = NULL;
			else
				cur->parent->right = NULL;
		}
		free(cur); cur = NULL;
		heapify_down(*root);
	}
	return (tmp);
}
