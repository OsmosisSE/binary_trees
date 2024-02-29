#include "binary_trees.h"

/**
 * tree_is_perfect - Checks if a binary tree is perfect recursively.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is perfect - the level of height. Otherwise - 0.
 */
static int tree_is_perfect(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (tree->left && tree->right)
	{
		l = 1 + tree_is_perfect(tree->left);
		r = 1 + tree_is_perfect(tree->right);
		if (r == l && r != 0 && l != 0)
			return (r);
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect.
 * A binary tree is considered perfect if all its levels are fully filled.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is perfect - 1. Otherwise - 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		return (tree_is_perfect(tree) != 0);
	}
}
