
#include "lists.h"

/**
 * find_listint_loop - function that find the loop in a linked list.
 * @head: pointer to a pointer to the first element of a linked list.
 * Return: address of the node where the loop starts, or NULL if no node.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fastPtr;
	listint_t *slowPtr;

	if (head == NULL)
		return (NULL);

	/* Implementation of Floyd's Algorithm */

	fastPtr = head;
	slowPtr = head;

	while (fastPtr && fastPtr->next && fastPtr->next->next)
	{
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
		if (slowPtr == fastPtr)
		{
			slowPtr = head;
			while (slowPtr != fastPtr)
			{
				slowPtr = slowPtr->next;
				fastPtr = fastPtr->next;
			}
			return (fastPtr);
		}
	}
	return (NULL);
}
