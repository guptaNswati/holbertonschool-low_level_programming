#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
* free_newList - frees newly craeted address list
* @h: head of the list
* Return: nothing
**/
void free_newList(adrsList *h)
{
	adrsList *frN;

	if (h != NULL)
	{
		while (h)
		{
			frN = h;
			h = (*h).next;
			free(frN);
		}
		h = NULL;
	}
}
/**
* free_list - free the non-cyclic list and counts the nodes freed
* @h: head of the list
* Return: number of nodes freed
**/
size_t free_list(listint_t **h)
{
	listint_t *freeH;
	size_t counter;

	counter = 0;
	if (*h == NULL)
	 	return (counter);

	while (*h)
	{
		freeH = *h;
		*h = (*(*h)).next;
		free(freeH);
		counter++;
	}
	*h = NULL;
	return (counter);
}


/**
* free_listint_safe - function that frees linked list
* @h: pointer to pointer to elements of type listint_t
* Return: the number of nodes in the list that were freed
**/
size_t free_listint_safe(listint_t **h)
{
	size_t counter;
	listint_t ***oldAdrs;
	adrsList *newList, *newHead;

	oldAdrs = &h;
	newHead = newList = NULL;
	while (*h)
	{
		while (newList)
		{
			if ((*newList).ptr == *h)
			{
				free_newList(newHead);
				counter = free_list(*oldAdrs);
				return (counter);
			}
			newList = (*newList).next;
		}
		newList = add_node(&newHead, (void *)*h);
		*h = (*(*h)).next;
	}
	free_newList(newHead);
	counter = free_list(*oldAdrs);
	return (counter);
}
