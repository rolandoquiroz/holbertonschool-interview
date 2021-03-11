
#include "sort.h"

int get_digits_number(int n);
int get_digit(int n, int position);
int _pow_recursion(int x, int y);
void algorithm_radix_sort(int *array, int *buckets, int size, int max_digits);

/**
 * radix_sort - Sorting an array of numbers using radix sort
 * @array: Array
 * @size: Size of the array
 * Return: Nothing
**/

void radix_sort(int *array, size_t size)
{
	int *buckets;
	int max_digits = 0, digit_actual_number, size_int, i;

	size_int = (int) size;

	if (array == NULL || size < 2)
		return;

	buckets = malloc(sizeof(int) * 10);
	if (buckets == NULL)
		return;

	for (i = 0; i < 10; i++)
		buckets[i] = 0;

	for (i = 0; i < size_int; i++)
	{
		digit_actual_number = get_digits_number(array[i]);
		if (digit_actual_number > max_digits)
			max_digits = digit_actual_number;
	}

	algorithm_radix_sort(array, buckets, size_int, max_digits);
}


/**
 * get_digits_number- Gets the number of digits from a number
 * @n: Number
 * Return: Number of digits
**/

int get_digits_number(int n)
{
	int digits = 0, result = n;

	do {
		result = result / 10;
		digits++;
	} while (result != 0);

	return (digits);
}

/**
 * get_digit - Gets a certain digit from a number
 * @n: Number
 * @position: Position
 * Return: Digit of that position
**/

int get_digit(int n, int position)
{
	int result;
	int power;

	power = _pow_recursion(10, position - 1);
	result = (n / power) % 10;

	return (result);
}

/**
 * _pow_recursion - Function that returns the factorial of a given number
 * @x: Base
 * @y: Power
 *
 * Return: Result of x raised to the power of y.
 */

int _pow_recursion(int x, int y)
{
	if (y == 0)
		return (1);
	else if (y < 0)
		return (-1);

	return (x * _pow_recursion(x, y - 1));
}

/**
 * algorithm_radix_sort - Sorting an array of numbers using radix sort
 * @array: Array
 * @buckets: Array of numbers from 0 to 9
 * @size: Size of the array
 * @max_digits: Maximum number of digits in the array
 * Return: Nothing
**/

void algorithm_radix_sort(int *array, int *buckets, int size, int max_digits)
{
	int *sorted_array;
	int iteration, i, digit;

	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
	{
		free(buckets);
		return;
	}

	for (iteration = 1; iteration <= max_digits; iteration++)
	{
		for (i = 0; i < 10; i++)
			buckets[i] = 0;

		for (i = 0; i < size; i++)
		{
			digit = get_digit(array[i], iteration);
			buckets[digit] += 1;
		}

		for (i = 1; i < 10; i++)
			buckets[i] += buckets[i - 1];

		for (i = (size - 1); i >= 0; i--)
		{
			digit = get_digit(array[i], iteration);
			sorted_array[buckets[digit] - 1] = array[i];
			buckets[digit] -= 1;
		}

		for (i = 0; i < size; i++)
			array[i] = sorted_array[i];

		print_array(array, size);
	}

	free(buckets);
	free(sorted_array);
}
