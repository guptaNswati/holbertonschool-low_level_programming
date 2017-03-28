#include "binary_trees.h"

/**
* free_queue - frees a queue holding level order nodes of binary tree
* @head: double pointer to head of queue
* Return: nothing
**/
void free_queue(queue **head)
{
	queue *tmp, *cur;

	if (!*head)
		return;
	cur = *head;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	*head = NULL;
}

/**
* add_in_end - adds a new node at the end of the queue
* @head: double pointer to head of queue
* @node: pointer to binary tree node for adding to queue
* Return: pointer to new node of queue, or NULL
**/
queue *add_in_end(queue **head, binary_tree_t *node)
{
	queue *tmp, *cur;

	if (!node)
		return (NULL);
	tmp = malloc(sizeof(queue));
	if (!tmp)
	{
		free_queue(head);
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
* remove_front - removes first node of queue
* @head: double pointer to head of queue
* Return: first node
**/
binary_tree_t *remove_front(queue **head)
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
* heapify_up - restores the max heap property of max binary heap tree,
* by percolate up
* @new_node: pointer to new node
* Return: pointer to new root after restoring heap property
**/
heap_t *heapify_up(heap_t *new_node)
{
	int tmp;
	heap_t *cur = new_node;

	while (cur->parent)
	{
		if (cur->parent->n < cur->n)
		{
			tmp = cur->n;
			cur->n = cur->parent->n;
			cur->parent->n = tmp;
			new_node = cur->parent;
		}
		cur = cur->parent;
	}
	return (new_node);
}

/**
* heap_insert - inserts a value in Max Binary Heap
* @root: double pointer to the root node of the Heap to insert the value in
* @value: value to store in the node to be inserted
* Return: a pointer to the created node, or NULL on failure
**/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;
	binary_tree_t *tmp;
	queue *l_queue = NULL;

	if (!*root)
	{
		*root = binary_tree_node(*root, value);
		return (*root);
	}
	add_in_end(&l_queue, *root);
	while (l_queue)
	{
		tmp = remove_front(&l_queue);
		if (!tmp->left || !tmp->right)
		{
			free_queue(&l_queue);
			break;
		}
		add_in_end(&l_queue, tmp->left);
		add_in_end(&l_queue, tmp->right);
	}
	new_node = binary_tree_node(tmp, value);
	if (!new_node)
		return (NULL);
	if (!tmp->left)
		tmp->left = new_node;
	else
		tmp->right = new_node;
	return (heapify_up(new_node));
}
