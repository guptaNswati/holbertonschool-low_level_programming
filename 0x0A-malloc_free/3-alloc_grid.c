#include "holberton.h"
#include <stdlib.h>

/**
* alloc_grid - creates a 2d integer grid
* @width: number of columns
* @height: number of rows
* Return: pointer to grid or null
**/
int **alloc_grid(int width, int height)
{
	int **grid, i, j;

	if ((width || height) < 1)
		return (NULL);

	grid = malloc(sizeof(int) * height);

	for (i = 0; i < height; i++)
		grid[i] = malloc(sizeof(int) * width);

	if (grid == NULL)
		return (NULL);
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}
	return (grid);
}
