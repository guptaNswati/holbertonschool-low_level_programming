#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
* print_listint_safe - prints listint_t list, safe version
* @head: pointer to elements of type listint_t
* Return: the number of nodes in the list
**/
size_t print_listint_safe(const listint_t *head)
{
	size_t counter;
	const listint_t *prev, *nex;

	if (head == NULL)
		return (0);
	if ((*head).next == NULL)
	{
		printf("[%p] %d\n", (void *)head, (*head).n);
		return (1);
	}
	if ((*head).next == head)
	{
		printf("-> [%p] %d\n", (void *)head, (*head).n);
		exit (98);
	}
	counter = 0;
	prev = head;
	nex = (*head).next->next;
	while (prev != nex || (prev && nex))
	{
		printf("[%p] %d\n", (void *)prev, (*prev).n);
		prev = (*prev).next;
		nex = nex->next->next;
		/*	if (prev == nex)
		{
			printf("-> [%p] %d\n", (void *)prev, (*prev).n);
			exit(98);
			} */
		counter++;
	}
	return (counter);
}
