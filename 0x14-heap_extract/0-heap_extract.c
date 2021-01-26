#include "binary_trees.h"

/**
 * binary_tree_height - Function that measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: 1 if node is a leaf, otherwise 0. If node is NULL, return 0
 **/

size_t binary_tree_height(const heap_t *tree)
{
	size_t height_left = 0, height_right = 0;

	if ((tree == NULL) || ((tree->left == NULL) && (tree->right == NULL)))
		return (0);

	if (tree->left)
		height_left = binary_tree_height(tree->left);
	if (tree->right)
		height_right = binary_tree_height(tree->right);

	if (height_left >= height_right)
		return (height_left + 1);
	else
		return (height_right + 1);
}

/**
 * binary_tree_preorder - pre-order traversal that goes through a binary tree
 * @tree: pointer to root
 * @node: pointer to node in the tree
 * @h: height of the tree
 * @level: layer in the tree
 *
 * Return: Nothing
 **/

void binary_tree_preorder(heap_t *tree, heap_t **node, size_t h, size_t level)
{
	if (tree == NULL)
		return;
	if (h == level)
		*node = tree;

	level++;

	if (tree->left)
		binary_tree_preorder(tree->left, node, h, level);
	if (tree->right)
		binary_tree_preorder(tree->right, node, h, level);
}

/**
 * heap_extract - Function that extracts the root node from a Max Binary Heap
 * @root: is a double pointer to the root node of the heap
 *
 * Return: The value stored in the root node, otherwhise 0 on Fail
 **/

int heap_extract(heap_t **root)
{
	int value, v_aux;
	size_t level = 0;
	heap_t *aux, *node;

	if (!root || !*root)
		return (0);
	aux = *root;
	value = aux->n;
	if (!aux->left && !aux->right)
	{
		*root = NULL;
		free(aux);
		return (value);
	}
	binary_tree_preorder(aux, &node, binary_tree_height(aux), level);
	while (aux->left || aux->right)
	{
		if (!aux->right || aux->left->n > aux->right->n)
		{
			v_aux = aux->n;
			aux->n = aux->left->n;
			aux->left->n = v_aux;
			aux = aux->left;
		}
		else if (!aux->left || aux->left->n < aux->right->n)
		{
			v_aux = aux->n;
			aux->n = aux->right->n;
			aux->right->n = v_aux;
			aux = aux->right;
		}

	}
	aux->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	return (value);
}
