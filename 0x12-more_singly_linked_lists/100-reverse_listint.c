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

	if (*head != NULL)
	{
		if ((*(*head)).next == NULL)
			return (*head);

		/* Method 1
		   prev = *head;
		temp = (*(*head)).next;
		(*prev).next = NULL;
		while (temp != NULL)
		{
			prev = temp;
			temp = (*temp).next;
			(*prev).next = *head;
			*head = prev;
			} */
		/* Method 2 */
		temp = *head;
		*head = NULL;
		while (temp != NULL)
		{
			prev = (*temp).next;
			(*temp).next = *head;
			*head = temp;
			temp = prev; /* temp->next */
		}
		return (*head);
	}
	return (NULL);
}
