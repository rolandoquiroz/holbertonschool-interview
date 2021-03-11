#include "sort.h"

/**
 * findLargestNum - Sorts an array of integers in ascending order
 *              using the Radix sort algorithm.
 *              Implements the LSD radix sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
int findLargestNum(int *array, int size)
{

	int i;
	int largestNum = -1;

	for (i = 0; i < size; i++)
	{
		if (array[i] > largestNum)
			largestNum = array[i];
	}

	return (largestNum);
}

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
	int n = (int)size;
  /* Base 10 is used */
	int i;
	int semiSorted[n];
	int significantDigit = 1;
	int largestNum = findLargestNum(array, n);

  /* Loop until we reach the largest significant digit */
	while (largestNum / significantDigit > 0)
  	{

		int bucket[10] = { 0 };

    	/* Counts the number of "keys" or digits that will go into each bucket */
    	for (i = 0; i < n; i++)
			bucket[(array[i] / significantDigit) % 10]++;

    /**
     * Add the count of the previous buckets,
     * Acquires the indexes after the end of each bucket location in the array
		 * Works similar to the count sort algorithm
     **/
    	for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];

    /* Use the bucket to fill a "semiSorted" array */
    for (i = size - 1; i >= 0; i--)
    	semiSorted[--bucket[(array[i] / significantDigit) % 10]] = array[i];


    for (i = 0; i < n; i++)
    	array[i] = semiSorted[i];

    /* Move to next significant digit */
    significantDigit *= 10;

	print_array(array, n);
}
}
