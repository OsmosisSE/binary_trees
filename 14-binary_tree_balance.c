#include "binary_trees.h"

/**
 * binary_tree_height_b - Measures height of a binary tree for a balanced tree
 * @tree: Pointer to the root of the binary tree
 * Return: The height of the tree
 */
size_t binary_tree_height_b(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = tree->left ? 1 + binary_tree_height_b(tree->left) : 0;
	size_t right_height = tree->right ? 1 + binary_tree_height_b(tree->right) : 0;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root of the binary tree
 * Return: The balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int left_height = (int)binary_tree_height_b(tree->left);
	int right_height = (int)binary_tree_height_b(tree->right);

	return (left_height - right_height);
}
