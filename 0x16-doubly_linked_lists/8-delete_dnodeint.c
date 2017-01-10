#include "lists.h"

/**
* delete_dnodeint_at_index - deletes the node at given index of a list
* @head: pointer to head of the list
* @index: index to delete from, starting from 0
* Return: 1 on success or -1 on failure
**/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int count;
	dlistint_t *tmp;

	if (*head == NULL || head == NULL)
		return (-1);
	if (index == 0)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp), tmp = NULL;
		return (1);
	}
	count = 1, tmp = (*head)->next;
	while (tmp->next)
	{
		if (index == count)
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			free(tmp), tmp = NULL;
			return (1);
		}
		count++, tmp = tmp->next;
	}
	if (tmp && index == count)
	{
		free(tmp);
		tmp->prev->next = NULL;
		return (1);
	}
	return (-1);
}
