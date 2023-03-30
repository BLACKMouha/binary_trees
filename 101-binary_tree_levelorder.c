#include "binary_trees.h"
/** ========== Prototypes ========== */
void print_current_level(
	const binary_tree_t *tree,
	int level,
	void (*func)(int));
void print_level_order(const binary_tree_t *tree, void (*func)(int));
int height(const binary_tree_t *tree);
/** ================================ */

/**
 * binary_tree_levelorder - traverses a binary tree using level-order traversal
 * Prototype: void binary_tree_levelorder(const binary_tree_t *tree,
 *                                        void (*func)(int));
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to the function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	print_level_order(tree, func);
}

/**
 * print_level_order - prints nodes for each level from left to right
 * Prototype: void print_level_order(const binary_tree_t *tree,
 *                                   void (*func)(int));
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to the function to call for each node
 */
void print_level_order(const binary_tree_t *tree, void (*func)(int))
{
	int h, i;

	if (!tree || !func)
		return;

	h = height(tree);
	for (i = 1; i <= h; i++)
		print_current_level(tree, i, func);
}


/**
 * print_current_level - all nodes of a level from left to right
 * Prototype: void print_current_level(const binary_tree_t *tree,
 *                                     int level,
 *                                     void (*func)(int))
 * @tree: pointer to the root node of the tree to traverse
 * @level: level to traverse
 * @func: pointer to the function to call for each node
 */
void print_current_level(const binary_tree_t *tree,
	int level,
	void (*func)(int))
{
	if (!tree)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_current_level(tree->left, level - 1, func);
		print_current_level(tree->right, level - 1, func);
	}
}

/**
 * height - measures the height of a binary tree
 * Prototype: size_t binary_tree_height(const binary_tree_t *tree);
 * @tree: pointer to the root node of the tree to measure the height
 * Return: the number of edges of the longest path from root to any leaf node
 */
int height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	int lheight = height(tree->left);
	int rheight = height(tree->right);

	if (lheight > rheight)
		return (lheight + 1);
	else
		return (rheight + 1);
}
