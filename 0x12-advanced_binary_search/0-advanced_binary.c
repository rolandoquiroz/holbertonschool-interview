#include "search_algos.h"

void print_array(int *array, int a, int j);
/**
 * advanced_binary - finds first occurence of element in array
 * @array: the sorted array to search
 * @size: size of array
 * @value: value to find
 * Return: index of value or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	int i = 0, j = (int)size - 1, k = 0, aux;

	if (size < 1)
		return (-1);

	while (i <= j)
	{
		k = (((j + i) / 2));
		printf("Searching in array:");
		aux = i;
		print_array(array, aux, j);
		printf("\n");
		if (array[k] == value)
		{
			if (value == array[k - 1])
			{
				j = k;
			}
			else
			{
				return (k);
			}
		}
		else if (value > array[k])
		{
			i = k + 1;
		}
		else
		{
			if (size % 2)
			{
				j = k;
			}
			else
			{
				j = k - 1;
			}
		}
	}
	return (-1);
}

/**
 * print_array - search value in an array with advanced binary search
 * @array: array with values to search
 * @i: minimum position to index
 * @j: max position
 * Return: Not return
 */
void print_array(int *array, int i, int j)
{
	if (i <= j)
	{
		printf(" %d", array[i]);
		if (i < j)
			printf(",");
		print_array(array, i + 1, j);
	}
}
