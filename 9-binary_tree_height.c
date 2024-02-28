#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0, height_right = 0;

	if (tree == NULL)
		return (0);

	/* Calculate the height of the left subtree */
	if (tree->left)
		height_left = 1 + binary_tree_height(tree->left);

	/* Calculate the height of the right subtree */
	if (tree->right)
		height_right = 1 + binary_tree_height(tree->right);

	/* Return the maximum height between left and right subtrees */
	return (height_left > height_right ? height_left : height_right);
}
