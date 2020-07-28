#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to pointer of first node of a sorted singly listint_t list
 * @number: int to be inserted into a sorted singly listint_t list
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new = NULL;
	listint_t **current = head;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		new->next = *head;
	}
	else
	{
		while (*current != NULL && (*current)->n < new->n)
			current = &((*current)->next);
		new->next = *current;
		*current = new;
	}
	return (new);
}

