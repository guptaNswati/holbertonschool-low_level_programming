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
	adrsList *new, *frN;

	new = malloc(sizeof(adrsList));
	if (new == NULL)
	{
		while (*head)
		{
			frN = *head;
			*head = (*(*head)).next;
			free(frN);
		}
		*head = NULL;
		return (NULL);
	}
	(*new).ptr = ptr;
	(*new).next = *head;
	*head = new;
	return (*head);
}

/**
* print_listint_safe - prints listint_t list, safe version
* @head: pointer to elements of type listint_t
* Return: the number of nodes in the list
**/
size_t print_listint_safe(const listint_t *head)
{
	size_t counter;
	const listint_t *temp;
	adrsList *newList, *newHead, *frNew;

	if (head == NULL)
		return (0);

	counter = 0;
	newHead = newList = NULL;
	while (head)
	{
		while (newList)
		{
			if ((*newList).ptr == head)
			{
				printf("-> [%p] %d\n", (void *)head, (*head).n);
				while (newHead)
				{
					frNew = newHead;
					newHead = (*newHead).next;
					free(frNew);
				}
				frNew = NULL;
				exit(98);
			}
			newList = (*newList).next;
		}
		printf("[%p] %d\n", (void *)head, (*head).n);
		newList = add_node(&newHead, (void *)head);
		head = (*head).next;
		counter++;
	}
	while (newHead)
	{
		frNew = newHead;
		newHead = (*newHead).next;
		free(frNew);
	}
	frNew = NULL;
	return (counter);
}
