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
	heap_t *new_father = NULL;
	heap_t *ans = NULL;

	int size;

	size = binary_tree_size(*root);

	if (size >= 0 && size < 3)
	{
		if (size == 0)
		{
			*root = binary_tree_node(NULL, value);
			ans = (*root);
		}
		if (size == 1)
		{
			(*root)->left = binary_tree_node(*root, value);
			if (value > (*root)->n)
			{
				value = (*root)->n;
				(*root)->n = (*root)->left->n;
				(*root)->left->n = value;
			}
			ans = (*root)->left;
		}
		if (size == 2)
		{
			(*root)->right = binary_tree_node(*root, value);
			if (value > (*root)->n)
			{
				value = (*root)->n;
				(*root)->n = (*root)->right->n;
				(*root)->right->n = value;
			}
			ans = (*root)->right;
		}
		return (ans);
	}
	else
	{
		new_father = NthNode(*root, (size + 1) / 2);

		if (new_father->left == NULL)
		{
			new_father->left = binary_tree_node(new_father, value);
			if (value > new_father->n)
			{
				value = new_father->n;
				new_father->n = new_father->left->n;
				new_father->left->n = value;
			}
			ans = new_father->left;
			return (ans);
		}
		else if ((new_father->left != NULL) && (new_father->right == NULL))
		{
			new_father->right = binary_tree_node(new_father, value);
			if (value > new_father->n)
			{
				value = new_father->n;
				new_father->n = new_father->right->n;
				new_father->right->n = value;
			}
			ans = new_father->right;
			return (ans);
		}
	}

	return (ans);
}

int binary_tree_size(const binary_tree_t *tree)
{
	size_t size_left = 0, size_right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		size_left = binary_tree_size(tree->left);
	if (tree->right)
		size_right = binary_tree_size(tree->right);

	return (size_left + size_right + 1);
}

heap_t *NthNode(heap_t *root, int n)
{
	int bitIndex = 0;

	while (1)
	{
		if (1 << (bitIndex + 1) > n)
			break;
		bitIndex++;
	}

	bitIndex--;

	while (bitIndex >= 0)
	{
		int mask = (1 << bitIndex);

		if (n & mask)
			root = root->right;
		else
			root = root->left;
		bitIndex--;
	}
	return (root);
}
