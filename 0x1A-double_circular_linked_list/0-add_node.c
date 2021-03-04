#include "list.h"

List *add_node(List **list, char *str);
/**
 * add_node_end - add a node on the end.
 * @list: Double linked list.
 * @str: string value in the new node.
 *
 * Return: Memory addres to the new node.
 */
List *add_node_end(List **list, char *str)
{
	List *new, *last;

	new = add_node(list, str);

	last = (*list)->prev;

	last->next = new;
	new->next = *list;
	new->prev = last;
	(*list)->prev = new;

	return (new);
}

/**
 * add_node_begin - add a node on the beginning.
 * @list: Double linked list.
 * @str: string value in the new node.
 *
 * Return: Memory addres to the new node.
 */
List *add_node_begin(List **list, char *str)
{
	List *new, *last;

	new = add_node(list, str);

	last = (*list)->prev;

	new->next = (*list);
	new->prev = last;
	(*list)->prev = last->next = new;
	*list = new;

	return (new);
}

/**
 * add_node - add a node.
 * @list: Double linked list.
 * @str: string value in the new node.
 *
 * Return: Memory addres to the new node.
 */
List *add_node(List **list, char *str)
{
	List *new;

	if (list == NULL || str == NULL)
		return (NULL);

	new = (List *)malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}

	if (*list == NULL)
	{
		new->next = new->prev = new;
		*list = new;
	}

	return (new);
}
