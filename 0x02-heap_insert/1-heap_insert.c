#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Pointer to pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to new created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *ans = NULL;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		ans = (*root);
	}
	else
	{
		if ((*root)->left == NULL && (*root)->right == NULL)
		{
			(*root)->left = binary_tree_node(*root, value);

			if ((*root)->left->n > (*root)->n)
			{
				int temp = (*root)->n;
				(*root)->n = (*root)->left->n;
				(*root)->left->n = temp;
				return ((*root));
			}
			ans = (*root)->left;
		}

		if ((*root)->left != NULL && (*root)->right == NULL)
		{
			(*root)->right = binary_tree_node(*root, value);

			if ((*root)->right->n > (*root)->n)
			{
				int temp = (*root)->n;
				(*root)->n = (*root)->right->n;
				(*root)->right->n = temp;
				return ((*root));
			}
			ans = (*root)->right;
		}
	}
	return (ans);
}
