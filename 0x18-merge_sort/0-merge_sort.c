#include "sort.h"

/**
 * merge - Merge the arrays back together so that their elements are in order
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Returns: Nothing
 */
void merge(int *array, int *sub_array, int size)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, size / 2);
	printf("[right]: ");
	print_array(array + size / 2, size - size / 2);

	for (i = 0, j = size / 2, k = 0; k < size; k++)
	{
		if (j == size)
		{
			sub_array[k] = array[i++];
		}
		else
		{
			if (i == size / 2)
			{
				sub_array[k] = array[j++];
			}
			else
			{
				if (array[j] < array[i])
				{
					sub_array[k] = array[j++];
				}
				else
				{
					sub_array[k] = array[i++];
				}
			}
		}
	}

	for (i = 0; i < size; i++)
	{
		array[i] = sub_array[i];
	}

	free(sub_array);

	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge Sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Returns: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int *sub_array;

	if (size < 2 || array == NULL)
		return;

	sub_array = malloc(size * sizeof(int));
	if (sub_array == NULL)
		return;

	merge_sort(array, size / 2);
	merge_sort(array + size / 2, size - size / 2);
	merge(array, sub_array, size);
}
