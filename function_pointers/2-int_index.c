#include "function_pointers.h"

/**
 * int_index - searches for an integer using a comparison function
 * @array: array of integers
 * @size: number of elements in the array
 * @cmp: pointer to comparison function
 *
 * Return: index of first element for which cmp doesn't return 0,
 *         or -1 if no match or size <= 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array != NULL && cmp != NULL && size > 0)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]) != 0)
				return (i);
		}
	}
	return (-1);
}
