#include "search_algos.h"

/**
 * exponential_search - Searches for a value in a sorted array of integers
 * using the Exponential search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: The index where value is located, or -1 if not found
 *
 * Description: Prints the value checked in the array each time it compares.
 */
int exponential_search(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return (-1);

    size_t bound = 1;
    while (bound < size && array[bound] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
        bound *= 2;
    }

    size_t left = bound / 2;
    size_t right = (bound < size - 1) ? bound : size - 1;

    printf("Value found between indexes [%lu] and [%lu]\n", left, right);

    return (binary_search(array, left, right, value));
}

/**
 * binary_search - Searches for a value in a sorted array of integers
 * using the Binary search algorithm within a specific range
 * @array: Pointer to the first element of the array to search in
 * @left: The left index of the search range
 * @right: The right index of the search range
 * @value: Value to search for
 *
 * Return: The index where value is located, or -1 if not found
 */
int binary_search(int *array, size_t left, size_t right, int value)
{
    while (left <= right)
    {
        size_t mid = left + (right - left) / 2;
        printf("Searching in array: ");
        for (size_t i = left; i <= right; i++)
        {
            printf("%d", array[i]);
            if (i < right)
                printf(", ");
        }
        printf("\n");

        if (array[mid] == value)
            return (mid);
        else if (array[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return (-1);
}
