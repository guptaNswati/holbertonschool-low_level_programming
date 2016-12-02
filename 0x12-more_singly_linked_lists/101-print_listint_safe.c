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
/*	const listint_t *temp; */

	counter = 0;
	if (head != NULL)
	{
		while (head != NULL)
		{
			printf("[%p] %d\n", (void *)head, (*head).n);
			counter++;
			head = (*head).next;
			if (head == (*head).next)
			{
				break;
			}
		}
	}
/*		temp = head;
		while (1)
		{
			printf("[%p] %d\n", (void *)temp, (*temp).n);
			counter++;
			temp = (*temp).next;
			if (temp == head)
			{
				printf("coming in\n");
				printf("-> [%p] %d\n", (void *)temp, (*temp).n);
				return (0);
			}
			if (temp == NULL)
				break;
		}
	} */
	return (counter);
}
