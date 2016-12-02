#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
* add_node - function that adds a new node at the start of adrsList list
* @head: pointer to pointer to adrsList list
* @ptr: address to be added
* Return: the address of head, or NULL if it failed
**/
adrsList *add_node(adrsList **head, void *ptr)
{
	adrsList *new;

	new = malloc(sizeof(adrsList));
	if (new == NULL)
	{
		return (NULL);
	}
	(*new).ptr = ptr;
	(*new).next = *head;
	*head = new;
	return (*head);
}

/**
* free_aList - frees newly craeted address list
* @h: head of the list
**/
size_t free_aList(void* h)
{
	adrsList *frN;
	size_t counter;

	counter = 0;
	if (h == NULL)
		return (counter);
	while (h)
	{
		frN = h;
		h = h->next;
		free(frN);
		counter++;
	}
	h = NULL;
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
				counter += free_aList((void *)newHead);
				counter += free_aList((void *)*h);
				return (counter);
			}
			newList = (*newList).next;
		}
		newList = add_node(&newHead, (void *)*h);
		if (newList == NULL)
			break;
		*h = (*(*h)).next;
	}
	counter += free_aList((void *)newHead);
	counter += free_aList((void *)*h);
	return (counter);
}
