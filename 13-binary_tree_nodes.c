#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the number of nodes in a tree with children
 * @tree: Pointer to the root node of the tree
 * Return: Number of nodes with children
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	/* If the tree is empty, return 0 */
	if (tree == NULL)
		return (0);

	/* Count the current node if it has at least one child */
	size_t nodes = (tree->left || tree->right) ? 1 : 0;

	/* Recursively count nodes in the left and right subtrees */
	nodes += binary_tree_nodes(tree->left);
	nodes += binary_tree_nodes(tree->right);

	return (nodes);
}
