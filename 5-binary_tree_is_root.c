#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a node is a root
 * Prototype: int binary_tree_is_root(const binary_tree_t *node)
 * @node: pointer to the node to check
 * Return: 1 f node is a root, 0 if node is NULL or is not a root
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);
	return (!node->parent);
}
