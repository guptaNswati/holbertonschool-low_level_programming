#include "sort.h"

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
