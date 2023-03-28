#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * Prototype: binary_tree_t binary_tree_sibling(binary_tree_t *node);
 * @node: pointer to the node to find the sibling
 * Return: a pointer to the sibling if it exists, otherwise NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node)
		return (NULL);
	if (!node->parent)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	else if (node->parent->right == node)
		return (node->parent->left);
	else
		return (NULL);
}
