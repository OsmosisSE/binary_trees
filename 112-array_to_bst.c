#include "binary_trees.h"

/**
 * array_to_bst - Turns an array into a BST tree.
 * @array: The array to turn into a BST tree.
 * @size: The size of the array.
 *
 * Return: A pointer to the root node of the BST.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
