#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * Prototye: int binary_tree_is_full(const binary_tree_t *tree);
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the binary tree is full, 0 if NULL or not full
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	return (0);
}

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

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect binary tree
 * Prototype: int binary_tree_is_perfect(const binary_tree_t *tree);
 * @tree: pointer to root node of the tree to check
 * Return: 1 if it is a perfect binary, 0 if empty or not a perfect binary tree
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (binary_tree_is_leaf(tree->left) && binary_tree_is_leaf(tree->right))
		return (1);
	if (binary_tree_is_full(tree))
		return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	return (0);
}
