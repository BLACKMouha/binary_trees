#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_size - measures the size of a binary tree
 * Prototype: size_t binary_tree_size(const binary_tree_t *tree);
 * @tree: pointer to the root node of the tree to measure the size
 * Return: the number of nodes of the binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
