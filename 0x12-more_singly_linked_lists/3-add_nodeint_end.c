#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
* add_nodeint_end - function that adds a new node at the end of listint_t list
* @head: pointer to pointer to listint_t list
* @n: int to copy to new node
* Return: the address of the new element, or NULL if it failed
**/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new, *temp;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	(*new).n = n;
	(*new).next = NULL;

	if (*head == NULL)
		*head = new;

	else if ((*(*head)).next == NULL)
		(*(*head)).next = new;
	else
	{
		temp = *head;
		while ((*temp).next != NULL)
			temp = (*temp).next;
		(*temp).next = new;
	}
	return (new);
}
