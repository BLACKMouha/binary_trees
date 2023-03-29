#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * Prototype: size_t binary_tree_depth(const binary_tree_t *tree);
 * @tree: pointer to the root node of the tree to measure the depth
 * Return: the number of levels from root to a specific node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (!tree || !tree->parent)
		return (0);

	depth = tree->parent ? 1 + binary_tree_depth(tree->parent) : 0;
	return (depth);
}
