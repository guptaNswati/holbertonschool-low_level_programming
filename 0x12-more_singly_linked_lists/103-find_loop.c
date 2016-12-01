#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
* find_listint_loop - finds the loop of the listint_t list
* @head: pointer to elements of type listint_t
* Return: address of the node where the loop starts, or NULL if no loop
**/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *prev, *nex, *temp;

	prev = nex = head;
	while (prev && nex && (*nex).next)
	{
		temp = prev;
		prev = (*prev).next;
		nex = nex->next->next;
		if (prev == nex)
			return (temp);
	}
	return (NULL);
}
