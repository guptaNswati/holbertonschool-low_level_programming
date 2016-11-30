#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
* get_nodeint_at_index - finds the nth node of a listint_t linked list
* @head: pointer to the head of the list
* @index: node to find
* Return: nth node or NULL
**/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *temp;
	unsigned int i;

	if (head != NULL)
	{
		temp = head;
		i = 0;
		while (temp != NULL)
		{
			if (i == index)
				return (temp);
			temp = (*temp).next;
			i++;
		}
	}
	return (NULL);
}
