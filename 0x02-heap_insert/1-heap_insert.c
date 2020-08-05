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
	int size = binary_tree_size(*root);

	if (size >= 0 && size < 3)
	{
		if (size == 0)
		{
			*root = binary_tree_node(NULL, value);
			return ((*root));
		}
		if (size == 1)
		{
			(*root)->left = binary_tree_node(*root, value);
			if (value > (*root)->n)
			{
				swap(&(*root)->n, &(*root)->left->n);
				return ((*root));
			}
			return ((*root)->left);
		}
		if (size == 2)
		{
			(*root)->right = binary_tree_node(*root, value);
			if (value > (*root)->n)
			{
				swap(&(*root)->n, &(*root)->right->n);
				return ((*root));
			}
			return ((*root)->right);
		}
	}
	else
		return (o_heap_insert(root, value));
	return (NULL);
}

/**
 * o_heap_insert - Inserts a value into a Max Binary Heap
 * @root: Pointer to pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to new created node, or NULL on failure
 */
heap_t *o_heap_insert(heap_t **root, int value)
{
	heap_t *new_dad = NULL, *old_dad = NULL, *ans = NULL;
	int size = binary_tree_size(*root);

	old_dad = (*root);
	new_dad = kNode(*root, (size + 1) / 2);

	if (new_dad->left == NULL)
	{
		new_dad->left = binary_tree_node(new_dad, value);
		ans = new_dad->left;
		if (value > new_dad->n)
		{
			swap(&new_dad->n, &new_dad->left->n);
			ans = new_dad;
		}
		if (ans->n > old_dad->n)
		{
			swap(&new_dad->n, &old_dad->n);
			ans = old_dad;
		}
		return (ans);
	}
	else if ((new_dad->left != NULL) && (new_dad->right == NULL))
	{
		new_dad->right = binary_tree_node(new_dad, value);
		ans = new_dad->right;
		if (value > new_dad->n)
		{
			swap(&new_dad->n, &new_dad->right->n);
			ans = new_dad;
		}
		if (new_dad->n > old_dad->n)
		{
			swap(&new_dad->n, &old_dad->n);
			ans = old_dad;
		}
		return (ans);
	}
	return (NULL);
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
 * kNode - Function that gets next father to insert new child node
 * @root: Pointer to the root node of the tree to measure the size
 * @n: Size of the tree
 *
 * Return: If tree is NULL return 0
 */
heap_t *kNode(heap_t *root, int n)
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
 * swap - Function that swaps two ints
 * @x: Pointer to the root node of the tree to measure the size
 * @y: Size of the tree
 *
 * Return: Nothing
 */
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
