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

	if (*head == NULL)
		return (-1);
	if (*head && index == 0)
	{
		*head = (*head)->next;
		free((*head)->prev);
		(*head)->prev = NULL;
		return (1);
	}
	count = 1;
	tmp = (*head)->next;
	while (tmp->next)
	{
		if (index == count)
		{
			tmp->prev->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			free(tmp);
			tmp = NULL;
			return (1);
		}
		count++;
		tmp = tmp->next;
	}
	return (-1);
}
