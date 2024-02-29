#include "binary_trees.h"

/**
 * binary_tree_is_full - Check if a binary tree is full.
 * A binary tree is considered full if every node has either zero or two
 * children.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is full - 1. Otherwise - 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if ((tree->left == NULL && tree->right == NULL) ||
			(tree->left && tree->right))
	{
		return (binary_tree_is_full(tree->left) &&
				binary_tree_is_full(tree->right));
	}

	return (0);
}
