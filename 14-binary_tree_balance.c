#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_height - measures the height of a binary tree
 * Prototype: size_t binary_tree_height(const binary_tree_t *tree);
 * @tree: pointer to the root node of the tree to measure the height
 * Return: the number of edges of the longest path from root to any leaf node
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}


/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * Prototype: int binary_tree_balance(const binary_tree_t *tree);
 * @tree: pointer to the root node of the tree to count the semi-leaf
 * Return: the difference between heights' subtrees of right and left children
 * of the node in question.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int l, r;

	if (!tree)
		return (0);
	l = (!tree->left) ? -1 : (int)binary_tree_height(tree->left);
	r = (!tree->right) ? -1 : (int)binary_tree_height(tree->right);

	return (l - r);
}
