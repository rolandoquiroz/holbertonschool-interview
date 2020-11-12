#include <stdio.h>
#include <stdlib.h>
#include "search.h"

size_t len(skiplist_t *);
/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: head list pointer
 * @value: value to search
 *
 * Return: pointer to the value or NULL
**/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *left = list, *right = NULL;

	if (list == NULL)
	{
		return (NULL);
	}


	while (value > left->express->n)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		left->express->index, left->express->n);
		left = left->express;
		if (left->express == NULL)
		{
			break;
		}
	}

	if (left->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   left->express->index, left->express->n);
		printf("Value found between indexes [%lu] and [%lu]\n",
			   left->index, left->express->index);
	}
	else
	{
		printf("Value found between indexes [%lu] and [%lu]\n",
			   left->index, len(list));
	}

	right = left;

	while (value >= right->next->n)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   right->index, right->n);
		right = right->next;
		if (right->next == NULL || value == right->n)
		{
			break;
		}
	}

	printf("Value checked at index [%lu] = [%d]\n", right->index, right->n);
	if (right->next == NULL)
	{
		return (NULL);
	}

	return (right);
}

/**
 * len - Calculate length of the list
 * @list: is a pointer to the head of the skip list to measure in
 *
 * Return: The lenght of the list
 */
size_t len(skiplist_t *list)
{
	size_t n = 0;

	while (list->next)
	{
		n += 1;
		list = list->next;
	}
	return (n);
}
