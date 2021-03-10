#include "sort.h"

/**
*  _memset - Fills the first n bytes of the memory area
*      	pointed to by @s with the constant byte @c.
* @s: A pointer to the memory area to be filled.
* @c: The character to fill the memory area with.
* @n: The number of bytes to be filled.
*
* Return: A pointer to the filled memory area @s.
*/
void _memset(void *s, int c, size_t n)
{
    unsigned int index;
    unsigned char *memory = s, value = c;

    for (index = 0; index < n; index++)
	{
		memory[index] = value;
	}
}

/**
* _memcpy - Fills the first n bytes of the memory area
*      	pointed to by @s with the constant byte @c.
* @dest: A pointer to the memory area to be filled.
* @src: The character to fill the memory area with.
* @n: The number of bytes to be filled.
*
* Return: A pointer to the filled memory area @s.
*/
void _memcpy(void *dest, void *src, size_t n)
{
   /* Typecast src and dest addresses to (char *) */
   char *csrc = (char *)src;
   char *cdest = (char *)dest;

   /* Copy contents of src[] to dest[] */
	for (size_t i = 0; i < n; i++)
		cdest[i] = csrc[i];
}

/**
 * count_sort_radix - Sorts an array of integers in ascending order
 *              using the Radix sort algorithm.
 *              Implements the LSD radix sort algorithm.
 *
 * @a: The array to be sorted
 * @n: sort by the number of digits
 * @k: sort by the number of digits
 * @d: Number of elements in @array
 */

void count_sort_radix(int a[], int n, int k, int d)
{
	/* The value of each digit of all elements in a is in the range of [0,k]. */
	/* d means sort by the number of digits, 0 means sort by the ones digit, */
	/* 1 means press tens, 2 means press hundreds, and so on. */
	int *b, *c;
	int i;

	/* It is convenient to extract the value of a certain digit in a */
	int num = 1;

	b = (int *)malloc(sizeof(int) * n);
	if (b == NULL)
		return;

	c = (int *)malloc(sizeof(int) * (k + 1));
	if (c == NULL)
	{
		free(b);
		return;
	}

	 _memset(c, 0, sizeof(int) * (k + 1));

	while (d-- > 0)
		num *= k + 1;

	for (i = 0; i < n; i++)
	{
		c[a[i] / num % (k + 1)]++;
	}

	/* At this time, what is stored in c[i] is that */
	/* there are several numbers in a and the d bits are i */

	for (i = 1; i <= k; i++)
	{
		c[i] += c[i - 1];
	}
	/* At this time, c[i] stores the number of d bits in a<=i */

	for (i = n - 1; i >= 0; i--)
	{
		/* Put array[i] into the correct position in b */
		b[c[a[i] / num % (k + 1)] - 1] = a[i];
		/* Adjust the position pointer of b to avoid putting */
		/* the same element in the same position */
		c[a[i] / num % (k + 1)]--;
	}

	_memcpy(a, b, sizeof(int) * n); /*Copy the sort result to a*/

	free(c);
	free(b);
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
	int i, max_value, max_digit;
	int radix = 10;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array a */
	max_value = array[0];
	for (i = 1; i < n; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	/* Calculate the maximum number of digits */
	max_digit = 0;
	while (max_value)
	{
		max_digit++;
		max_value /= radix;
	}

	for (i = 0; i < max_digit; i++)
		count_sort_radix(array, n, radix - 1, i);
}
