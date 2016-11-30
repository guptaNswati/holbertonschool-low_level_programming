#include "lists.h"
#include <stdlib.h>

/**
* free_list - free a listint_t list
* @head: pointer to the head of the list
* Return: nothing
**/
void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = (*head).next;
		free(temp);
	}
}
