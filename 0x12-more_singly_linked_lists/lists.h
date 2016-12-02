#ifndef LINKEDLIST
#define LINKEDLIST

/**
* struct listint_s - singly linked list
* @n: integer
* @next: points to the next node
*
* Description: singly linked list node structure
* for Holberton project
*/
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

#include <stdlib.h>
int _putchar(char c);
size_t print_listint(const listint_t *h);
size_t listint_len(const listint_t *h);
listint_t *add_nodeint(listint_t **head, const int n);
listint_t *add_nodeint_end(listint_t **head, const int n);
void free_listint(listint_t *head);
void free_listint2(listint_t **head);
int pop_listint(listint_t **head);
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index);
int sum_listint(listint_t *head);

/**
* insert_nodeint_at_index - inserts a new node at given index, starting at 0
* @head: pointer to the head pointer of the list
* @index: position to add the node at
* @n: data of the new node
* Return: Address of the new node, or NULL if it fails
**/
listint_t *insert_nodeint_at_index(listint_t **head,
				   unsigned int index, int n);

int delete_nodeint_at_index(listint_t **head, unsigned int index);
listint_t *reverse_listint(listint_t **head);

/**
* struct adrsList - linkedlist of addresses
* @ptr: address
* @next: pointer to next adrsList node
* Description: list for saving once met addresses
**/
typedef struct adrsList
{
	void *ptr;
	struct adrsList *next;
} adrsList;

adrsList *add_node(adrsList **head, void *ptr);
void free_adrsList(adrsList *h);
size_t print_listint_safe(const listint_t *head);
void free_newList(adrsList *h);
size_t free_list(listint_t **h);
size_t free_listint_safe(listint_t **h);
listint_t *find_listint_loop(listint_t *head);
#endif
