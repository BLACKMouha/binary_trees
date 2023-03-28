#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * Prototype: size_t binary_tree_nodes(const binary_tree_t *tree);
 * @tree: pointer to the root node of the tree to count the semi-leaf
 * Return: the number of nodes that have at least 1 child
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	else if (!tree->left && !tree->right)
		return (0);
	else
		return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
