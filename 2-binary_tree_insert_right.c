#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * Prototype: binary_tree_t *binary_tree_insert_right(binary_tree_t *parent,
 *                                                   int value);
 * @parent: pointer to the node to insert the right-child in.
 * @value: the value to put in the new node
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new = binary_tree_node(parent, value);

	if (!new)
		return (NULL);

	if (parent->right)
	{
		parent->right->parent = new;
		new->right = parent->right;
	}
	parent->right = new;
	return (new);
}