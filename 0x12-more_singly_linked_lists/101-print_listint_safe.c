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
	const listint_t *temp, *next;

	counter = 0;
	temp = head;
	next = head->next;
	while (1)
	{
		if (!next || !next->next)
			break;
		else if (next == temp || next->next == temp)
		{
			printf("coming in\n");
			printf("-> [%p] %d\n", (void *)temp, (*temp).n);
			return (0);
		}
		else
		{
			printf("[%p] %d\n", (void *)temp, (*temp).n);
			counter++;
			temp = (*temp).next;
			next = next->next->next;
		}
	}
	return (counter);
}
