#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
* insert_nodeint_at_index - inserts new  node in listint_t list at given index
* @head: pointer to head pointer of the list
* @index: node to insert at
* @n: data of the new node
* Return: the address of the new node, or NULL
**/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int index, int n)
{
	listint_t *temp, *prev, *new;
	unsigned int i;

	if (*head != NULL)
	{
		new = malloc(sizeof(listint_t));
		if (new == NULL)
			return (NULL);
		(*new).n = n;
		(*new).next = NULL;

		if (index == 0)
		{
			(*new).next = *head;
			*head = new;
			return (new);
		}
		i = 1;
		prev = *head;
		temp = (*(*head)).next;
		while (temp != NULL)
		{
			if (i == index)
			{
				(*prev).next = new;
				(*new).next = temp;
				return (new);
			}
			prev = temp;
			temp = (*temp).next;
			i++;
		}
	}
	return (NULL);
}
