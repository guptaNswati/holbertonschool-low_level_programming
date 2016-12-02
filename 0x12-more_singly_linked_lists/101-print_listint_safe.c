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
		free_adrsList(*head);
		exit(98);
	}
	(*new).ptr = ptr;
	(*new).next = *head;
	*head = new;
	return (*head);
}

/**
* free_adrsList - frees newly craeted address list
* @h: head of the list
**/
void free_adrsList(adrsList *h)
{
	adrsList *frN;

	while (h)
	{
		frN = h;
		h = (*h).next;
		free(frN);
	}
}

/**
* print_listint_safe - prints listint_t list, safe version
* @head: pointer to elements of type listint_t
* Return: the number of nodes in the list
**/
size_t print_listint_safe(const listint_t *head)
{
	size_t counter;
	adrsList *newList, *newHead;

	counter = 0;
	if (head == NULL)
		return (counter);

	newHead = newList = NULL;
	while (head)
	{
		while (newList)
		{
			if ((*newList).ptr == head)
			{
				printf("-> [%p] %d\n", (void *)head, (*head).n);
				free_adrsList(newHead);
				return (counter);
			}
			newList = (*newList).next;
		}
		printf("[%p] %d\n", (void *)head, (*head).n);
		newList = add_node(&newHead, (void *)head);
		head = (*head).next;
		counter++;
	}
	free_adrsList(newHead);
	return (counter);
}
