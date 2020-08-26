#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 *         An empty list is considered a palindrome.
 */
int is_palindrome(listint_t **head)
{
	listint_t *first_half_reversed, *auxiliar = *head;
	unsigned int number_of_nodes, counter;
	int ans = 1;


	if (head == NULL)
		return (1);

	number_of_nodes = size_of_list(*head);

	first_half_reversed = NULL;
	counter = 0;
	while (counter < number_of_nodes / 2)
	{
		add_nodeint_start(&first_half_reversed, auxiliar->n);
		auxiliar = auxiliar->next;
		counter++;
	}

	if (number_of_nodes % 2)
	{
		auxiliar = auxiliar->next;
		counter++;
	}

	ans = are_list_equal(auxiliar, first_half_reversed);

	return (ans);
}

/**
 * size_of_list - Returns the number of nodes of a listint_t list
 * @h: pointer to head of list
 * Return: number of nodes
 */
unsigned int size_of_list(const listint_t *h)
{
	const listint_t *current;
	unsigned int n; /* number of nodes */

	current = h;
	n = 0;
	while (current != NULL)
	{
		current = current->next;
		n++;
	}

	return (n);
}

/**
 * add_nodeint_start - Add a new node at the beginning of listint_t list
 * @head: Pointer to pointer to head of the listint_t list
 * @n: Integer to be included in new node
 * Return: address of new element or null if not successful
 */

listint_t *add_nodeint_start(listint_t **head, const int n)
{
	listint_t *new = NULL;

	new = malloc(sizeof(listint_t));

	if (new != NULL)
	{
		new->n = n;
		new->next = *head;
		*head = new;
	}
	return (new);
}

/**
 * are_list_equal - Function to check if two listint_t list are equal
 * @head1: Pointer to pointer to head of the listint_t list
 * @head2: Integer to be included in new node
 * Return: 1 if lists are equal or 0 if lists are not equal
 */

int are_list_equal(listint_t *head1, listint_t *head2)
{
	while (head1 != NULL && head2 != NULL)
	{
		if (head1->n != head2->n)
			return (0);

		head1 = head1->next;
		head2 = head2->next;
	}

	if (head1 != NULL)
		return (0);
	if (head2 != NULL)
		return (0);

	return (1);
}
