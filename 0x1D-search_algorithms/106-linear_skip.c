#include "search_algos.h"

/**
* linear_skip - searches for a value in a sorted skip list of integers,
* containing pointer to jump step, using the Jump search algorithm.
* @list: is a pointer to the head of the skip list to search in
* @value: is the value to search for
* Return: a pointer to the first node where value is located or else NULL
**/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *back_jump;

	if (!list)
		return (NULL);
	back_jump = list;
	list = list->express;
	while (list->express && list->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       list->index, list->n);
		back_jump = list;
		list = list->express;
	}
	printf("Value checked at index [%lu] = [%d]\n",
	       list->index, list->n);
	/* search last block */
	if (value > list->n)
	{
		back_jump = list;
		while (list->next)
			list = list->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
		       back_jump->index, list->index);
		while (back_jump)
		{
			printf("Value checked at index [%lu] = [%d]\n",
			       back_jump->index, back_jump->n);
			if (back_jump->n == value)
				return (back_jump);
			back_jump = back_jump->next;
		}
		return (NULL);
	}
	/* search the block */
	printf("Value found between indexes [%lu] and [%lu]\n",
	       back_jump->index, list->index);
	while (back_jump && back_jump != list)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       back_jump->index, back_jump->n);
		if (back_jump->n == value)
			return (back_jump);
		back_jump = back_jump->next;
	}
	return (NULL);
}
