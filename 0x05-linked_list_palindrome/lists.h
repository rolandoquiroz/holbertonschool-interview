#ifndef LISTS_H
#define LISTS_H

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

listint_t *add_nodeint_end(listint_t **head, const int n);
size_t print_listint(const listint_t *h);
void free_listint(listint_t *head);
int is_palindrome(listint_t **head);
unsigned int size_of_list(const listint_t *h);
listint_t *add_nodeint_start(listint_t **head, const int n);
int are_list_equal(listint_t *head1, listint_t *head2);

#endif /* LISTS_H */
