#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - nested loop to make grid
 * @width: width input
 * @height: height input
 * Return: pointer to 2 dim. array
 */
int **alloc_grid(int width, int height)
{
	int **gridin;
	int j, k;

	if (width <= 0 || height <= 0)
		return (NULL);

	gridin = malloc(sizeof(int *) * height);

	if (gridin == NULL)
		return (NULL);

	for (j = 0; j < height; j++)
	{
		gridin[j] = malloc(sizeof(int) * width);

		if (gridin[j] == NULL)
		{
			for (; j >= 0; j--)
				free(gridin[j]);

			free(gridin);
			return (NULL);
		}
	}

	for (j = 0; j < height; j++)
	{
		for (k = 0; k < width; k++)
			gridin[j][k] = 0;
	}

	return (gridin);
}
