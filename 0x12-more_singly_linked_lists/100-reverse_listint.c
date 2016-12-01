#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
* reverse_listint - reverses a listint_t list
* @head: pointer to head pointer of the list
* Return: head of reversed list
**/
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev, *temp;

	if (*head == NULL)
		return (NULL);

	if ((*(*head)).next == NULL)
		return (*head);

	prev = *head;
	*head = NULL;
	while (prev != NULL)
	{
		temp = (*prev).next;
		(*prev).next = *head;
		*head = prev;
		prev = temp;
	}
	return (*head);
}
