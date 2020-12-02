#include "sort.h"

void sift_down(int array[], int root, int bottom, size_t size);

/**
 * heap_sort - function that implements a heap sort algorithm
 * @array: The array to sort
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	int i, temp;

	for (i = (size / 2); i >= 0; i--)
	{
		sift_down(array, i, size - 1, size);
	}

	for (i = size - 1; i >= 1; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		sift_down(array, 0, i - 1, size);
	}
}

/**
 * sift_down - order according binary distribution
 * @array: pointer to array
 * @root: actual size
 * @bottom: actual position
 * @size: total size
 */
void sift_down(int array[], int root, int bottom, size_t size)
{
	int maxChild = root * 2 + 1, otherChild, temp;

	if (maxChild < bottom)
	{
		otherChild = maxChild + 1;
		maxChild = (array[otherChild] > array[maxChild]) ? otherChild : maxChild;
	}
	else
	{
		if (maxChild > bottom)
			return;
	}

	if (array[root] >= array[maxChild])
		return;

	temp = array[root];
	array[root] = array[maxChild];
	array[maxChild] = temp;
	print_array(array, size);
	sift_down(array, maxChild, bottom, size);
}
