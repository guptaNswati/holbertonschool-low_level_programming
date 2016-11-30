#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
* add_nodeint - function that adds a new node at the beginning of listint_t list
* @head: pointer to pointer to listint_t list
* @n: integer to copy
* Return: the address of the new element, or NULL if it failed
**/
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	(*new).n = n;
	(*new).next = *head;
	*head = new;
	return (*head);
}
