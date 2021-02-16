#include "sort.h"

/**
 * merge - Merge the arrays back together so that their elements are in order
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @m: Middle index
 *
 * Returns: Nothing
 */
void merge(int *array, int size, int m)
{
	int i, j, k;
	int *sub_array;

	sub_array = malloc(size * sizeof(int));
	if (sub_array == NULL)
		return;

	for (i = 0, j = m, k = 0; k < size; k++)
	{
		if (j == size)
		{
			sub_array[k] = array[i++];
		}
		else 
		{
			if (i == m)
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
	int m;

	if (size < 2)
		return;
	m = size / 2;
	
	merge_sort(array, m);
	merge_sort(array + m, size - m);
	merge(array, size, m);
}
