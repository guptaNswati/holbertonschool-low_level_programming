#include "binary_trees.h"

typedef struct node_list
{
	int n;
	struct node_list *next;
} node_l;

typedef struct list_of_list
{
	node_l *node;
	struct list_of_list *next;
} list_l;

node_l *add_end(node_l **head, int n)
{
	node_l *tmp, *cur;

	tmp = malloc(sizeof(node_l));
	if (!tmp)
		return (NULL);
	tmp->n = n;
	tmp->next = NULL;

	if (!*head)
	{
		*head = tmp;
		return (tmp);
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = tmp;
	return (tmp);
}

list_l *add_tolist(list_l **head, node_l *node)
{
	list_l *tmp, *cur;

	tmp = malloc(sizeof(list_l));
	if (!tmp)
		return (NULL);
	tmp->node = node;
	tmp->next = NULL;
	if (!*head)
	{
		*head = tmp;
		return (tmp);
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = tmp;
	return (tmp);
}

int list_size(list_l **head_l)
{
	int count = 0;
	list_l *tmp = *head_l;

	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

node_l *get_node(list_l **head_l, int level)
{
	int i;
	list_l *tmp = *head_l;

	for (i = 0; i < level && tmp; i++)
	{
		if (i == level - 1)
			return (tmp->node);
		tmp = tmp->next;
	}
	return (NULL);
}

void level_order_traversal(const binary_tree_t *tree, list_l **head_l, int level)
{
	node_l *head_n = NULL;

	if (!tree)
		return;
        /* each list is containing common level nodes,
	   if level not contained in list, add it */
	if (level > list_size(head_l))
	{
		head_n = add_end(&head_n, tree->n);
		add_tolist(head_l, head_n);
	}
	else
	{
		head_n = get_node(head_l, level);
		add_end(&head_n, tree->n);
	}
	level_order_traversal(tree->left, head_l, level + 1);
	level_order_traversal(tree->right, head_l, level + 1);
}

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	list_l *head_l = NULL;
	node_l *cur;

	level_order_traversal(tree, &head_l, 1);
	while (head_l)
	{
		cur = head_l->node;
		while (cur)
		{
			func(cur->n);
			cur = cur->next;
		}
		head_l = head_l->next;
	}
}
