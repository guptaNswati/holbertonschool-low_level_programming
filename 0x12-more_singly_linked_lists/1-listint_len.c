#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
* listint_len - function that returns the number of elements in listint_t
* @h: pointer to elements of type listint_t
* Return: the number of nodes in the list
**/
size_t listint_len(const listint_t *h)
{
	size_t counter;

	counter = 0;
	while (h != NULL)
	{
		h = (*h).next;
		counter++;
	}
	return (counter);
}
