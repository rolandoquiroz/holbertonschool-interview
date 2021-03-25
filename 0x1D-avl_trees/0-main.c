#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Function that creates a binary tree node
 * @parent: Pointer to the parent node of the node to create
 * @value: Value to put in the new node
 *
 * Return: Pointer to new node or NULL
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	node = (binary_tree_t *) malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * basic_tree - Build a basic binary tree
 *
 * Return: A pointer to the created tree
 */
binary_tree_t *basic_tree(void)
{
	binary_tree_t *root;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 128);
	root->left->right = binary_tree_node(root->left, 54);
	root->right->right = binary_tree_node(root, 402);
	root->left->left = binary_tree_node(root->left, 10);
	return (root);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root;
	int avl;

	root = basic_tree();

	binary_tree_print(root);
	avl = binary_tree_is_avl(root);
	printf("Is %d avl: %d\n", root->n, avl);
	avl = binary_tree_is_avl(root->left);
	printf("Is %d avl: %d\n", root->left->n, avl);

	root->right->left = binary_tree_node(root->right, 97);
	binary_tree_print(root);
	avl = binary_tree_is_avl(root);
	printf("Is %d avl: %d\n", root->n, avl);

	root = basic_tree();
	root->right->right->right = binary_tree_node(root->right->right, 430);
	binary_tree_print(root);
	avl = binary_tree_is_avl(root);
	printf("Is %d avl: %d\n", root->n, avl);

	root->right->right->right->left = binary_tree_node(root->right->right->right, 420);
	binary_tree_print(root);
	avl = binary_tree_is_avl(root);
	printf("Is %d avl: %d\n", root->n, avl);
	return (0);
}
