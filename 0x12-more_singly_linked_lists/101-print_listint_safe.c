#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
* print_listint_safe - prints all the elements of a listint_t list, safe version
* @h: pointer to elements of type listint_t
* Return: the number of nodes in the list
**/
size_t print_listint_safe(const listint_t *head)
{
	size_t counter;

	if (head == NULL)
	{
	      	printf("-> [%p] ", (void *)head);
		exit(98);
	}
	counter = 0;
	while (head != NULL)
	{
		printf("[%p] %d\n", (void *)head, (*head).n);
		head = (*head).next;
		counter++;
	}
	return (counter);
}
