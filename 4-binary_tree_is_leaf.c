#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf node
 * @node: Pointer to the node to check
 *
 * Return: 1 if the node is a leaf, 0 otherwise
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	/* Check if the node exists and has no children */
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1); /* Node is a leaf */

	return (0); /* Node is not a leaf or is NULL */
}
