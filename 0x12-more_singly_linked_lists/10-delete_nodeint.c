#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
* delete_nodeint_at_index - deletes a node in listint_t list at given index
* @head: pointer to head pointer of the list
* @index: node to be deleted
* Return: 1 if it succeeded, -1 if it failed
**/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *prev;
	unsigned int i;

	if (*head != NULL)
	{
		if (index == 0)
		{
			temp = *head;
			*head = (*(*head)).next;
			free(temp);
			return (1);
		}
		i = 1;
		prev = *head;
		temp = (*(*head)).next;
		while (temp != NULL)
		{
			if (i == index)
			{
				(*prev).next = (*temp).next;
				free(temp);
				return (1);
			}
			prev = temp;
			temp = (*temp).next;
			i++;
		}
	}
	return (-1);
}
