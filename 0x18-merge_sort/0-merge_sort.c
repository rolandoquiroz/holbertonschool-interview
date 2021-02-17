#include "sort.h"

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
	int *temp;

	if (size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	to_merge(array, temp, 0, size);
	free(temp);
}

/**
 * to_merge - Merge the arrays back together
 *            so that their elements are in order
 * @array: List of data
 * @temp: Holder for array
 * @start: Starting index
 * @end: Ending index
 *
 * Returns: Nothing
 */
void to_merge(int *array, int *temp, int start, int end)
{
	int mid;

	if (end - start > 1)
	{
		mid = start + (end - start) / 2;
		to_merge(array, temp, start, mid);
		to_merge(array, temp, mid, end);
		merger(array, temp, start, mid, end);
	}
}

/**
 * merger - Merges divided arrays into one
 * @array: List of data
 * @temp: Holder for array
 * @start: Starting index
 * @mid: Middle index
 * @end: Ending index
 *
 * Returns: Nothing
**/
void merger(int *array, int *temp, int start, int mid, int end)
{
	int i, j, k = 0;

	printf("Merging...\n");
	printf("[start]: ");
	print_array(array + start, mid - start);
	printf("[end]: ");
	print_array(array + mid, end - mid);
	for (i = start, j = mid; i < mid && j < end; k++)
	{
		if (array[i] < array[j])
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = array[j];
			j++;
		}
	}
	while (i < mid)
	{
		temp[k] = array[i];
		i++;
		k++;
	}
	while (j < end)
	{
		temp[k] = array[j];
		j++;
		k++;
	}
	for (i = 0, k = start; k < end; k++)
	{
		array[k] = temp[i];
		i++;
	}
	printf("[Done]: ");
	print_array(array + start, end - start);
}
