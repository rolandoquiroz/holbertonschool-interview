#include "sort.h"



void swap(unsigned *a, unsigned *b) {
    unsigned tmp = *a;
    *a = *b;
    *b = tmp;
}

/* sort unsigned ints */
void rad_sort_u(unsigned *from, unsigned *to, unsigned bit)
{
	if (!bit || to < from + 1) return;
 
	unsigned *ll = from, *rr = to - 1;
	for (;;) {
		/* find left most with bit, and right most without bit, swap */
		while (ll < rr && !(*ll & bit)) ll++;
		while (ll < rr &&  (*rr & bit)) rr--;
		if (ll >= rr) break;
		swap(ll, rr);
	}
 
	if (!(bit & *ll) && ll < to) ll++;
	bit >>= 1;
 
	rad_sort_u(from, ll, bit);
	rad_sort_u(ll, to, bit);
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
	size_t i;
	unsigned *x = (unsigned*) array;
 
	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++) 
            x[i] ^= -2147483648;
 
        rad_sort_u(x, x + size, -2147483648);
 
        for (i = 0; i < size; i++) 
            x[i] ^= -2147483648;


}
