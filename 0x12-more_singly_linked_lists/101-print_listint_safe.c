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

	counter = 0;
	prev = nex = head;
	while (prev && nex && (*nex).next)
	{
		printf("[%p] %d\n", (void *)prev, (*prev).n);
		prev = (*prev).next;
		nex = nex->next->next;
		if (prev == nex)
		{
			printf("-> [%p] %d\n", (void *)prev, (*prev).n);
			exit(98);
		}
		counter++;
	}
	return (counter);
}
