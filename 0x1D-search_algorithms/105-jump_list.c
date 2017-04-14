#include "search_algos.h"
#include <math.h>

/**
* print_list_range - prints range of linear search block
* @start: start index of block
* @end: end index of block
* Return: nothing
**/
void print_list_range(size_t start, size_t end)
{
	printf("Value found between indexes [%lu] and [%lu]\n", start, end);
}

/**
* print_list_elements - prints each element of the list
* @index: index of element
* @n: value of element
* Return: nothing
**/
void print_list_elements(size_t index, int n)
{
	printf("Value checked at index [%lu] = [%d]\n", index, n);
}

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
	listint_t *back;

	if (!list || size == 0)
		return (NULL);
	jump = sqrt(size);
	back = list;
	while (list && list->index != jump)
		list = list->next;
	while (list && list->n < value)
	{
		print_list_elements(jump, list->n);
		jump += sqrt(size);
		back = list;
		if (jump >= size)
		{
			while (list->next)
				list = list->next;
			print_list_elements(list->index, list->n);
			print_list_range(back->index, list->index);
			while (back && back->index <= list->index)
			{
				print_list_elements(back->index, back->n);
				back = back->next;
			}
			return (NULL);
		}
		while (list && list->index != jump)
			list = list->next;
	}
	print_list_elements(jump, list->n);
	print_list_range(back->index, list->index);
	while (back && back->index <= jump)
	{
		print_list_elements(back->index, back->n);
		if (back->n == value)
			return (back);
		back = back->next;
	}
	return (NULL);
}
