#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
* print_listint - prints all the elements of a listint_t list
* @h: pointer to elements of type listint_t
* Return: the number of nodes in the list
**/
size_t print_listint(const listint_t *h)
{
	size_t counter;

	counter = 0;
	while (h != NULL)
	{
		printf("%d\n", (*h).n);
		h = (*h).next;
		counter++;
	}
	return (counter);
}
