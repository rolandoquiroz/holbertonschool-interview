#include "sort.h"

/**
 * radix_sort - Sorts an array of integers in ascending order
 *              using the Radix sort algorithm.
 *              Implements the LSD radix sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
	int MAX = 10;
	int n = (int)size;
	int i, bucket[MAX], maxVal = 0, digitPosition = 1;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < n; i++)
	{
		if (array[i] > maxVal)
			maxVal = array[i];
	}

	while (maxVal / digitPosition > 0)
	{
		/* reset counter */
		int digitCount[10] = {0};

		/* count pos-th digits (keys) */
		for (i = 0; i < n; i++)
			digitCount[array[i] / digitPosition % 10]++;

		/* accumulated count */
		for (i = 1; i < 10; i++)
			digitCount[i] += digitCount[i - 1];

		/* To keep the order, start from back side */
		for (i = n - 1; i >= 0; i--)
			bucket[--digitCount[array[i] / digitPosition % 10]] = array[i];

		/* rearrange the original array using elements in the bucket */
		for (i = 0; i < n; i++)
			array[i] = bucket[i];

		/* move up the digit position */
		digitPosition *= 10;

		print_array(array, n);
	}
}
