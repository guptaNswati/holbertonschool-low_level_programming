#include "lists.h"

/**
* insert_dnodeint_at_index - inserts a new node at given index in the list
* @head: pointer to head of the list
* @idx: index to add at, starting from 0
* @n: value of new node
* Return: new node or null
**/
dlistint_t *insert_dnodeint_at_index(dlistint_t **head, unsigned int idx,
				     int n)
{
	unsigned int count;
	dlistint_t *tmp, *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n, new->prev = new->next = NULL;
	if (*head == NULL && idx == 0)
	{
		*head = new;
		return (new);
	}
	if (*head && idx == 0)
	{
		new->next = *head;
		(*head)->prev = new, *head = new;
		return (new);
	}
	count = 1, tmp = (*head)->next;
	while (tmp->next)
	{
		if (idx == count)
		{
			tmp->prev->next = new, new->prev = tmp->prev;
			new->next = tmp, tmp->prev = new;
			return (new);
		}
		count++;
		tmp = tmp->next;
	}
	if (tmp && count + 1 == idx)
	{
		tmp->next = new, new->prev = tmp;
		return (new);
	}
	free(new);
	return (NULL);
}
