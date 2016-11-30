#include "lists.h"
#include <stdlib.h>

/**
* pop_listint - deletes the head node of a listint_t list
* @head: pointer to the head of the list
* Return: head node's data (n) or 0
**/
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n;

	if (*head != NULL)
	{
		temp = *head;
		*head = (*(*head)).next;
		n = (*temp).n;
		free(temp);
		return (n);
	}
	return (0);
}
