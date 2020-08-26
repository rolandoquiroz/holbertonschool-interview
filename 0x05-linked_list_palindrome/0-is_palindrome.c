#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int is_palindrome(listint_t **head)
{
	return (is_sublist_palindrome(head, *head));
}

/**
 * is_sublist_palindrome - Check if linked sublist is palindrome recursively
 * @left: pointer to pointer of first node of listint_t list
 * @right: pointer to last node of listint_t list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 *			An empty list is considered a palindrome.
 */
int is_sublist_palindrome(listint_t **left, listint_t *right)
{
	int ans;

	if (right == NULL)
		return (1);

	if (is_sublist_palindrome(left, right->next) == 0)
		return (0);

	if ((*left)->n == right->n)
		ans = 1;
	else
		ans = 0;
	(*left) = (*left)->next;

	return (ans);
}
