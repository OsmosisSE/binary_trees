#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Tree to go through
 * Return: The height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		l = 1 + binary_tree_height(tree->left);
	if (tree->right)
		r = 1 + binary_tree_height(tree->right);

	return ((l > r) ? l : r);
}

/**
 * binary_tree_depth - depth of specified node from root
 * @tree: node to check the depth
 * Return: 0 is it is the root or number of depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}

/**
 * linked_node - Creates a linked list node and adds it to the list
 * @head: Pointer to the head of the linked list
 * @tree: Node to store
 * @level: Depth of the node to store
 * Return: Nothing
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *new, *aux;

	new = malloc(sizeof(link_t));
	if (new == NULL)
		return;

	new->n = level;
	new->node = tree;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		aux = *head;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = new;
	}
}

/**
 * recursion - Recursively traverses the tree and stores each node
 *             in a linked list using linked_node function
 * @head: Pointer to the head of the linked list
 * @tree: Node to check
 * Return: Nothing
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree != NULL)
	{
		level = binary_tree_depth(tree);
		linked_node(head, tree, level);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}

/**
 * binary_tree_levelorder - Traverses a binary tree in level-order
 *                          and performs a function on each node
 * @tree: Root node of the tree
 * @func: Function to execute on each node
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *aux;
	size_t height = 0, count = 0;

	if (!tree || !func)
		return;

	height = binary_tree_height(tree);
	head = NULL;
	recursion(&head, tree);

	while (count <= height)
	{
		aux = head;
		while (aux != NULL)
		{
			if (count == aux->n)
				func(aux->node->n);
			aux = aux->next;
		}
		count++;
	}

	while (head != NULL)
	{
		aux = head;
		head = head->next;
		free(aux);
	}
}
