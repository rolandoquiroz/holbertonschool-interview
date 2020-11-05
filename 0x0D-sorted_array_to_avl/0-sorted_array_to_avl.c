#include "binary_trees.h"
/**
* insert_new_avl_node - builds an AVL tree from an array
* @array: pointer to the first element of the array to be converted
* @start: the first element array index
* @end: the last element array index
* @parent: pointer to the parent of the new node
* Return: binary tree, otherwise NULL
*/
avl_t *insert_new_avl_node(int *array, size_t start, size_t end, avl_t *parent)
{
	size_t half;
	avl_t *root;

	if (start > end)
	{
		return (NULL);
	}


	half = start + (end - start) / 2;
	root = new_avl_node(parent, array[half]);
	if (!root)
	{
		return (NULL);
	}

	if (half != start)
	{
		root->left = insert_new_avl_node(array, start, half - 1, root);
	}

	if (half != end)
	{
		root->right = insert_new_avl_node(array, half + 1, end, root);
	}


	return (root);
}

/**
* new_avl_node - Creates a new avl_node
* @parent: pointer to the array
* @n: size of the array
* Return: the pointer of the node, otherwise NULL
*/
avl_t *new_avl_node(avl_t *parent, size_t n)
{
	avl_t *new = NULL;

	new = (avl_t *)malloc(sizeof(avl_t));

	if (new == NULL)
	{
		return (NULL);
	}

	new->n = n;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from an array
 *
 * @array: pointer to the array to be converted
 * @size: size of the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	if (!array || !size)
	{
		return (NULL);
	}

	root = insert_new_avl_node(array, 0, size - 1, NULL);
	return (root);
}
