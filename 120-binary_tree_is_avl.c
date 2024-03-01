#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0, height_r = 0;

	if (tree)
	{
		height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	}
	return (height_l > height_r ? height_l : height_r);
}

/**
 * is_avl - Checks if a binary tree is a valid AVL tree recursively
 * @tree: Pointer to the root node of the tree
 * @min: Minimum value allowed for a node in the tree
 * @max: Maximum value allowed for a node in the tree
 * Return: 1 if the tree is an AVL tree, 0 otherwise
 */
int is_avl(const binary_tree_t *tree, int min, int max)
{
	size_t height_l, height_r, balance;

	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	height_l = binary_tree_height(tree->left);
	height_r = binary_tree_height(tree->right);
	balance = height_l > height_r ? height_l - height_r : height_r - height_l;

	if (balance > 1)
		return (0);

	return (is_avl(tree->left, min, tree->n - 1) &&
			is_avl(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree
 * Return: 1 if the tree is an AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_avl(tree, INT_MIN, INT_MAX));
}
