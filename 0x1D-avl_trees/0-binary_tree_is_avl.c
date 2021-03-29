#include "binary_trees.h"

int check_order(binary_tree_t *, int, int);
int binary_tree_is_bst(const binary_tree_t *);
size_t binary_tree_height(const binary_tree_t *);
int binary_tree_balance(const binary_tree_t *);

/**
* binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
* @tree: Pointer to the root node of the tree to check.
*        If tree is NULL, return 0.
*
* Return: 1 if tree is a valid AVL Tree, and 0 otherwise.
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance, bst;

	if (!tree)
		return (0);

	balance = binary_tree_balance(tree);

	if (balance <= 1 && balance >= -1)
		balance = 1;
	else
		balance = 0;

	bst = binary_tree_is_bst(tree);

	if (bst && balance)
		return (1 * (tree->left ? binary_tree_is_avl(tree->left) : 1) *
				(tree->right ? binary_tree_is_avl(tree->right) : 1));

	return (0);
}

/**
* check_order - Checks if all nodes are less or higher than the root.
* @tree: subtree to evaluate.
* @n: Value of the root node.
* @dir: 0 for left (check less values) 1 for right (higher values).
* Return: 1 if correct order, 0 if not.
*/
int check_order(binary_tree_t *tree, int n, int dir)
{
	if (tree == NULL)
		return (1);
	if (dir)
		return (1 * tree->n > n ? (check_order(tree->right, n, dir) *
			check_order(tree->left, n, dir)) : 0);
	else
		return (1 * tree->n < n ? (check_order(tree->right, n, dir) *
			check_order(tree->left, n, dir)) : 0);
}

/**
* binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree.
* @tree: Pointer to the root node of the tree to check.
*
* Return: 1 if tree is a valid BST, and 0 otherwise.
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree || !check_order(tree->left, tree->n, 0) ||
		!check_order(tree->right, tree->n, 1))
		return (0);

	if ((!tree->left || tree->left->n < tree->n) &&
		(!tree->right || tree->right->n > tree->n))
		return (1 * (tree->left ? binary_tree_is_bst(tree->left) : 1) *
			(tree->right ? binary_tree_is_bst(tree->right) : 1));

	return (0);
}

/**
* binary_tree_height - Measures the height of a binary tree.
* @tree: Pointer to the root node of the tree to measure the height.
*
* Return: The height of the tree.
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0, height_right = 0;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
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
* binary_tree_balance - Measures the balance factor of a binary tree.
* @tree: Pointer to the root node of the tree to measure the balance factor.
*
* Return: Balance factor.
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left = binary_tree_height(tree->left);
	else
		left = -1;

	if (tree->right)
		right = binary_tree_height(tree->right);
	else
		right = -1;

	return (left - right);
}
