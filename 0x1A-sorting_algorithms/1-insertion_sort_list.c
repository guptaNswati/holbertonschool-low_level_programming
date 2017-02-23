#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *\in ascending order using the Insertion sort algorithm
 * @list - pointer to the given doubly linked list
 * Return: returns nothing
 */
void insertion_sort_list(listint_t **list)
{
	size_t size;
	unsigned int i, j;
	listint_t *pre, *cur, *tmp;

	size = size_of_list(*list);
	for(i = 1; i < size; ++i)
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
