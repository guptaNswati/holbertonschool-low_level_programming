#include "sort.h"

/**
* swap_list - swap nodes of a doubly linkedlist
* @tmp: current node to be swapped with its next node
* @list: pointer to head pointer of list
* Return: nothing
**/
void swap_list(listint_t *tmp, listint_t **list)
{
	listint_t *cur;

	cur = tmp->next;
	tmp->next = cur->next;
	if (tmp->next)
		tmp->next->prev = tmp;
	if (tmp->prev)
		tmp->prev->next = cur;
	else
		*list = cur;
	cur->prev = tmp->prev;
	cur->next = tmp;
	tmp->prev = cur;
	print_list(*list);
}

/**
* cocktail_sort_list - sorts a doubly linked list of integers in
* ascending order using the Cocktail shaker sort algorithm
* @list: pointer to list to be sorted
* Return: nothing
**/
void cocktail_sort_list(listint_t **list)
{
	size_t size;
	listint_t *tmp;

	if (!list || !*list)
		return;
	size = size_of_list(*list);
	if (size < 2)
		return;

	tmp = *list;
	while (tmp->next)
	{
		if (tmp->n > tmp->next->n)
		{
			swap_list(tmp, list);
			continue;
		}
		tmp = tmp->next;
	}
	tmp = tmp->prev;
	while (tmp)
	{
		if (tmp->n > tmp->next->n)
		{
			swap_list(tmp, list);
			continue;
		}
		tmp = tmp->prev;
	}
}

/**
* size_of_list - returns the size of the given linked list
* @list: given linked list
* Return: returns the size of the given list
*/
size_t size_of_list(listint_t *list)
{
	size_t size;
	listint_t *tmp;

	tmp = list;
	size = 0;
	while (tmp)
	{
		tmp = tmp->next;
		++size;
	}
	return (size);
}
