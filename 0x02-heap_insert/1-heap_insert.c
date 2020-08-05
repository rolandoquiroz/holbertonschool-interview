#include "binary_trees.h"x

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Pointer to pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to new created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_dad = NULL;
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
		new_dad = NthNode(*root, (size + 1) / 2);

		if (new_dad->left == NULL)
		{
			new_dad->left = binary_tree_node(new_dad, value);
			if (value > new_dad->n)
			{
				value = new_dad->n;
				new_dad->n = new_dad->left->n;
				new_dad->left->n = value;
			}
			ans = new_dad->left;
			return (ans);
		}
		else if ((new_dad->left != NULL) && (new_dad->right == NULL))
		{
			new_dad->right = binary_tree_node(new_dad, value);
			if (value > new_dad->n)
			{
				value = new_dad->n;
				new_dad->n = new_dad->right->n;
				new_dad->right->n = value;
			}
			ans = new_dad->right;
			return (ans);
		}
	}

	return (ans);
}

/**
 * binary_tree_size - Function that measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: If tree is NULL return 0
 */
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

/**
 * NthNode - Function that gets next father to insert new child node
 * @root: Pointer to the root node of the tree to measure the size
 * @n: Size of the tree
 *
 * Return: If tree is NULL return 0
 */
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

/**
 * swapper - Function that swaps two ints
 * @a: Pointer to the root node of the tree to measure the size
 * @b: Size of the tree
 *
 * Return: Nothing
 */
void swapper(int a, int b)
{
	int temp = a;

	a = b;
	b = temp;
}
