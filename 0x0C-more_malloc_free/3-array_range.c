#include <stdlib.h>
#include "main.h"

/**
 * *array_range - creates an array of integers
 * @min: minimum range of values stored
 * @max: maximum range of values stored and number of elements
 *
 * Return: pointer to the new array
 */
int *array_range(int min, int max)
{
	int *ptarr;
	int x, size;

	if (min > max)
		return (NULL);

	size = max - min + 1;

	ptarr = malloc(sizeof(int) * size);

	if (ptarr == NULL)
		return (NULL);

	for (x = 0; min <= max; x++)
		ptarr[x] = min++;

	return (ptarr);
}
