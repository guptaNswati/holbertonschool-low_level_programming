#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
* free_listint_safe - free a listint_t list, safe version
* @h: pointer to the header pointer of the list
* Return: size of the list that was free'd
**/
size_t free_listint_safe(listint_t **h)
{
	listint_t *temp;
	size_t len;

	len = 0;
	while (*h != NULL)
	{
		temp = *h;
		*h = (*(*h)).next;
		free(temp);
		len++;
	}
	*h = NULL;
	return (len);
}
