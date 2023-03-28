#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * Prototype: binary_tree_t *binary_tree_uncle(binary_tree_t *node);
 * @node: pointer to the node to find the uncle
 * Return: if exists, pointer of the uncle of the node, otherwise NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	else if (node->parent->parent->right == node->parent)
		return (node->parent->parent->left);
	else
		return (NULL);
}
