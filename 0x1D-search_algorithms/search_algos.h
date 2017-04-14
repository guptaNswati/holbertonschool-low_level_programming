#ifndef SEARCH_ALGO
#define SEARCH_ALGO

#include <stdio.h>
#include <stdlib.h>

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);

int binary_helper(int *array, size_t start, size_t end, int value);
int advanced_binary(int *array, size_t size, int value);

/**
* struct listint_s - singly linked list
*
* @n: Integer
* @index: Index of the node in the list
* @next: Pointer to the next node
*
* Description: singly linked list node structure
* for Holberton project
*/
typedef struct listint_s
{
	int n;
	size_t index;
	struct listint_s *next;
} listint_t;

listint_t *jump_list(listint_t *list, size_t size, int value);
void print_list(const listint_t *list);
void free_list(listint_t *list);
listint_t *create_list(int *array, size_t size);

/**
* struct skiplist_s - Singly linked list with an express lane
*
* @n: Integer
* @index: Index of the node in the list
* @next: Pointer to the next node
* @express: Pointer to the next node in the express lane
*
* Description: singly linked list node structure with an express lane
* for Holberton project
*/
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

skiplist_t *linear_skip(skiplist_t *list, int value);
void init_express(skiplist_t *list, size_t size);
skiplist_t *create_skiplist(int *array, size_t size);
void free_skiplist(skiplist_t *list);
void print_skiplist(const skiplist_t *list);


#endif
