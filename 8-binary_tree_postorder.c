#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverse a binary tree using post-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: This function traverses the binary tree in post-order fashion,
 * applying the given function to each node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	/* Check if both the tree and the function exist */
	if (tree == NULL || func == NULL)
		return;

	/* Recursively traverse the left subtree */
	binary_tree_postorder(tree->left, func);

	/* Recursively traverse the right subtree */
	binary_tree_postorder(tree->right, func);

	/* Apply the function to the current node */
	func(tree->n);
}
