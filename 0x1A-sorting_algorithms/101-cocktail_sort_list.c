#include "sort.h"

/**
* cocktail_sort_list - sorts a doubly linked list of integers in
* ascending order using the Cocktail shaker sort algorithm
* @list: pointer to list to be sorted
* Return: nothing
**/
void cocktail_sort_list(listint_t **list)
{
	size_t size;

	if (!list || !*list)
		return;
	size = size_of_list(*list);
	if (size < 2)
		return;
}
