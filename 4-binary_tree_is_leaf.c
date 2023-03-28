#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * Prototype: int  binary_tree_is_leaf(binary_tree_t *node);
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, 0 if node is NULL or is not a leaf.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	return ((!node->left && !node->right));
}
