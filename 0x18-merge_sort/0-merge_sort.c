#include "sort.h"

/**
 * merge - Merge the arrays back together so that their elements are in order
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Returns: Nothing
 */
void merge(int *array, int size)
{
	int i, j, k;
	int *sub_array;

	sub_array = malloc(size * sizeof(int));
	if (sub_array == NULL)
		return;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, size / 2);
	printf("[right]: ");
	print_array(array + size / 2, size - size / 2);

	for (i = 0, j = size / 2, k = 0; k < size; k++)
	{
		sub_array[k] = j == size ? array[i++]
		: i == size / 2 ? array[j++]
		: array[j] < array[i] ? array[j++]
		: array[i++];
	}

	for (i = 0; i < size; i++)
		array[i] = sub_array[i];

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
	if (size < 2 || array == NULL)
		return;

	merge_sort(array, size / 2);
	merge_sort(array + size / 2, size - size / 2);
	merge(array, size);
}
