#include <stdlib.h>
#include "holberton.h"

/**
* *_realloc -  reallocates a memory block using malloc and free
* @ptr: void pointer
* @old_size: already allocated size
* @new_size: new size to allocate
* Return: pointer to newly allocated memory or null
**/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned char *np, *lp;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	np = ptr;
	lp = np;
	ptr = malloc(new_size * sizeof(void *));

	if (ptr == NULL)
		return (NULL);

	i = 0;
	if (new_size > old_size)
	{
		while (i < old_size)
		{
			np++;
			i++;
		}
		ptr = lp;
		return (ptr);
	}
	/* if new_size < old_size */
	while (i < new_size)
	{
		np--;
		i++;
	}
	ptr = lp;
	return (ptr);
}
