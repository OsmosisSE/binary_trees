#include "binary_trees.h"

/**
 * bst_search - Searches for a specific value in the BST tree.
 * @tree: A pointer to the root node of the BST tree.
 * @value: The value to search for.
 *
 * Return: If the value is found, a pointer to the node containing the value.
 *         Otherwise, NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	if (value > tree->n)
		return (bst_search(tree->right, value));

	return ((bst_t *)tree);
}
