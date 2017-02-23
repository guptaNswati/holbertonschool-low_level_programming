#include "sort.h"

/**
* insertion_sort_list - sorts a doubly linked list of integers
* in ascending order using the Insertion sort algorithm
* @list - pointer to the given doubly linked list
* Return: returns nothing
*/
void insertion_sort_list(listint_t **list)
{
	size_t size;
	unsigned int i, j;
	listint_t *pre, *cur, *tmp;

	if (list == NULL || *list == NULL)
		return;

	size = size_of_list(*list);
	if (size < 2)
		return;

	for (i = 1; i < size; ++i)
	{
		cur =  *list;
		for (j = 0; j < i; ++j)
			cur = cur->next;
		pre = cur->prev;
		for (j = 0; j < i; ++j)
		{
			if (pre->n > cur->n)
			{
				tmp = pre->prev;
				pre->prev = cur;
				pre->next = cur->next;
				cur->prev = tmp;
				cur->next = pre;

				if (tmp != NULL)
					tmp->next = cur;
				else
					*list = cur;

				if (pre->next != NULL)
					pre->next->prev = pre;

				pre = cur->prev;
				print_list(*list);
			}
			else
				break;
		}
	}
}


/**
* size_of_list - returns the size of the given linked list
* @list - given linked list
* Return: returns the size of the given list
*/
size_t size_of_list(listint_t *list)
{
	size_t size = 0;

	while (list != NULL)
	{
		list = list->next;
		++size;
	}
	return (size);
}
