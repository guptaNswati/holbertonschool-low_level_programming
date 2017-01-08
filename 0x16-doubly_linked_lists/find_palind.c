#include "lists.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
* is_palind - creates a linkedlist of the the given numbers digits to check
* if the number is palindrome or not
* @product: number to be checked
* Return: 1 on succes, else -1
**/
int is_palind(int product)
{
	dlistint_t *head, *tmp, *cur;
	int count, i;

	head = NULL;
	/* create a linkedlist of products digits */
	while (product != 0)
	{
		add_dnodeint(&head, product % 10);
		product /= 10;
	}
	count = 1;
	/* make tmp point to end of the list */
	tmp = cur = head;
	while (tmp->next)
	{
		count++;
		tmp = tmp->next;
	}
	i = 0;
	while (i <= count / 2)
	{
		if (cur->n == tmp->n)
		{
			cur = cur->next;
			tmp = tmp->prev;
		}
		else
		{
			free_dlistint(head);
			return (-1);
		}
		i++;
	}
	free_dlistint(head);
	return (1);
}

/**
* find_palind - finds the largest palindrome of product of two three digit
* numbers and writes the result to a file
* Return: nothing
**/
void find_palind()
{
	int m, n, product, tmp, fd, i;
	char buf[6];

	tmp = 0;
	for (m = 999; m > 100; m--)
	{
		for (n = 999; n > 100; n--)
		{
			product = m * n;
			if (is_palind(product) == 1)
			{
				if (product > tmp)
					tmp = product;
			}
		}
	}
	fd = open("102-result", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
		exit (98);
	i = 0;
	while (tmp != 0)
	{
		buf[i] = tmp % 10 + '0';
		tmp /= 10;
		i++;
	}
	write(fd, buf, 6);
}
