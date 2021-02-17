#include "sort.h"

/**
 * merge - Merge the arrays back together so that their elements are in order
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @mid: Middle index
 *
 * Returns: Nothing
 */
void merge(int *array, int size, int mid)
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

	for (i = 0, j = mid, k = 0; k < size; k++)
	{
		if (j == size)
		{
			sub_array[k] = array[i++];
		}
		else
		{
			if (i == mid)
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

	printf("[Done]: ");
	print_array(sub_array, size);

	free(sub_array);
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
	int mid;

	if (size < 2 || array == NULL)
		return;

	mid = size / 2;

	merge_sort(array, mid);
	merge_sort(array + mid, size - mid);
	merge(array, size, mid);
}
