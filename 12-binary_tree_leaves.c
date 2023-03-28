#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * Prototype: size_t binary_tree_leaves(const binary_tree_t *tree);
 * @tree: pointer to the root node of the tree to count the number of leaves
 * Return: the number of leaves in the binary tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	else if (!tree->left && !tree->right)
		return (1);
	else
		return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
