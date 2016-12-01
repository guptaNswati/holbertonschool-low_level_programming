#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
* find_listint_loop - finds the loop in list using Floyd cycle detection algo
* @head: pointer to elements of type listint_t
* Return: address of the node where the loop starts, or NULL if no loop
**/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *prev, *nex;

	/* if theres nothing in list, return null */
	if (head == NULL)
		return (NULL);
	prev = nex = head;
	while (prev && nex && (*nex).next)
	{
		prev = (*prev).next;
		nex = (*nex).next->next;
		if (prev == nex)
		{
			/* Start back at begining to find where loop starts */
			prev = head;
			while (prev != nex)
			{
				prev = (*prev).next;
				nex = (*nex).next; /*not same as (*prev).next*/
			}
			return (prev);
		}
	}
	/* could find the loop, return null */
	return (NULL);
}
