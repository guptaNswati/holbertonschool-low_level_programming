#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	dlistint_t *head;

	head = NULL;
	insert_dnodeint_at_index(&head, 0, 4096); 
	print_dlistint(head);
 	add_dnodeint_end(&head, 0);
	add_dnodeint_end(&head, 1);
	add_dnodeint_end(&head, 2);
	add_dnodeint_end(&head, 3);
	add_dnodeint_end(&head, 4);
	add_dnodeint_end(&head, 98);
	add_dnodeint_end(&head, 402);
	add_dnodeint_end(&head, 1024);
	print_dlistint(head);
	printf("-----------------(tset case begins)\n");
	printf("[res] %p\n", (void *)insert_dnodeint_at_index(&head, 91, 4096));
	print_dlistint(head);
	printf("-----------------(test case ends)\n");

/*	insert_dnodeint_at_index(&head, 0, 4096);
	insert_dnodeint_at_index(&head, 0, 4096);
	insert_dnodeint_at_index(&head, 1, 4096);
	insert_dnodeint_at_index(&head, 11, 4096);
	print_dlistint(head);
	free_dlistint(head);
	head = NULL; */
	return (EXIT_SUCCESS);
}
