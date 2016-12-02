#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
* free_newList - frees newly craeted address list
* @h: head of the list
**/
void free_newList(adrsList* h)
{
	adrsList *frN;

	if (h != NULL)
	{
		while (h)
		{
			frN = h;
			h = h->next;
			free(frN);
		}
		h = NULL;
	}
}

/**
* free_listint_safe - function that frees linked list
* @h: pointer to pointer to elements of type listint_t
* Return: the number of nodes in the list that were freed
**/
size_t free_listint_safe(listint_t **h)
{
	size_t counter;
	listint_t *temp;
	adrsList *newList, *newHead;

	counter = 0;
	if (*h == NULL)
		return (counter);

	newHead = newList = NULL;
	while (*h)
	{
		while (newList)
		{
			if ((*newList).ptr == *h)
			{
				free_newList(newHead);
				*h = NULL;
				return (counter);
			}
			newList = (*newList).next;
		}
		newList = add_node(&newHead, (void *)*h);
		temp = *h;
		*h = (*(*h)).next;
		free(temp);
		counter++;
	}
	free_newList(newHead);
	*h = NULL;
	return (counter);
}
