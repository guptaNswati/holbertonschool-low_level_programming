#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
* sum_listint - calculates sum of all the data (n) of a listint_t list
* @head: pointer to the head of the list
* Return: sum of data of all nodes or 0
**/
int sum_listint(listint_t *head)
{
	int sum;

	sum = 0;
	if (head != NULL)
	{
		while (head != NULL)
		{
			sum += (*head).n;
			head = (*head).next;
		}
	}
	return (sum);
}
