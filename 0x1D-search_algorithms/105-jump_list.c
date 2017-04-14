#include "search_algos.h"
#include <math.h>

/**
* jump_list - searches for a value in a sorted list of integers using the
* Jump search algorithm.
* @list: is a pointer to the head of the list to search in
* @size: is the number of nodes in list
* @value: is the value to search for
* Return: a pointer to the first node where value is located or else -1
**/
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump;
	listint_t *back_jump;

	if (!list || size == 0)
		return (NULL);
	jump = sqrt(size);
	back_jump = list;
	while (list && list->index != jump)
		list = list->next;
	while (list && list->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", jump, list->n);
		jump += sqrt(size);
		back_jump = list;
		if (jump >= size)
		{
			while (list->next)
				list = list->next;
			printf("Value checked at index [%lu] = [%d]\n",
			       list->index, list->n);
			printf("Value found between indexes [%lu] and [%lu]\n",
			       back_jump->index, list->index);
			while (back_jump && back_jump->index <= list->index)
			{
				printf("Value checked at index [%lu] = [%d]\n",
				       back_jump->index, back_jump->n);
				back_jump = back_jump->next;
			}
			return (NULL);
		}
		while (list && list->index != jump)
			list = list->next;
	}
	printf("Value checked at index [%lu] = [%d]\n", jump, list->n);
	printf("Value found between indexes [%lu] and [%lu]\n",
	       back_jump->index, list->index);
	while (back_jump && back_jump->index <= jump)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       back_jump->index, back_jump->n);
		if (back_jump->n == value)
			return (back_jump);
		back_jump = back_jump->next;
	}
	return (NULL);
}
