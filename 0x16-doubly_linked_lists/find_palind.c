#include "lists.h"

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

int find_palind()
{
	int m, n, product, tmp;

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
	return (tmp);
}

int main()
{
	printf("%d\n", find_palind());
	return (0);
}
