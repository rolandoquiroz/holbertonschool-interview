#include "sort.h"

int get_max(int a[], int n);

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
	int bucket[10][10], bucket_cnt[10];
	int i, j, k, r, NOP = 0, divisor = 1, lar, pass;

	lar = get_max(array, n);

	while (lar > 0)
	{
		NOP++;
		lar /= 10;
	}

	for (pass = 0; pass < NOP; pass++)
	{
		for (i = 0; i < 10; i++)
		{
			bucket_cnt[i] = 0;
		}

		for (i = 0; i < n; i++)
		{
			r = (array[i] / divisor) % 10;
			bucket[r][bucket_cnt[r]] = array[i];
			bucket_cnt[r] += 1;
		}

		i = 0;
		for (k = 0; k < 10; k++)
		{
			for (j = 0; j < bucket_cnt[k]; j++)
			{
				array[i] = bucket[k][j];
				i++;
			}
		}

		divisor *= 10;

		print_array(array, n);
	}

}

/**
 * get_max - Sorts an array of integers in ascending order
 *
 * @a: The array to be sorted
 * @n: Number of elements in @array
 *
 * Return: Always 0
 */
int get_max(int a[], int n)
{
	int max = a[0];

	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];

	return (max);
}
