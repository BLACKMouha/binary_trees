#include "../binary_trees.h"
#include <stdio.h>

int sbinary_tree_depth(const binary_tree_t *tree);
/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * Prototype: size_t binary_tree_depth(const binary_tree_t *tree);
 * @tree: pointer to the root node of the tree to measure the depth
 * Return: the number of levels from root to a specific node
 */
int sbinary_tree_depth(const binary_tree_t *tree)
{
	int depth;

	if (!tree)
		return (-1);
	if (!tree->parent)
		return (0);

	depth = tree->parent ? 1 + sbinary_tree_depth(tree->parent) : 0;
	return (depth);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int depth;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    depth = sbinary_tree_depth(root);
    printf("Depth of %d: %d\n", root->n, depth);
    depth = sbinary_tree_depth(root->right);
    printf("Depth of %d: %d\n", root->right->n, depth);
    depth = sbinary_tree_depth(root->left->right);
    printf("Depth of %d: %d\n", root->left->right->n, depth);
    depth = sbinary_tree_depth(root->left->right->right);
    printf("Depth of %s: %d\n", "(nil)", depth);
    return (0);
}