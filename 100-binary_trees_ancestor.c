#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * Prototype: binary_tree_t *binary_trees_ancestor(
 *                              const binary_tree_t *first,
 *                              const binary_tree_t *second);
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 * if it exists, otherwise NULL
 */
binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first,
	const binary_tree_t *second)
{
	if (!first && !second)
		return (NULL);
	if (first && !second)
		return ((binary_tree_t*) first);
	if(!first && second)
		return ((binary_tree_t*) second);
	if (first == second)
		return ((binary_tree_t*) first);
	if (first->parent == second)
		return ((binary_tree_t*)second);
	if (first == second->parent)
		return((binary_tree_t*)first);
	if (first->parent == second->parent)
		return ((binary_tree_t*)first->parent);
	if (first->parent == second->parent->parent)
		return ((binary_tree_t*)first->parent);
	if (first->parent->parent == second->parent)
		return ((binary_tree_t*)second->parent);
	if (first->parent->parent->parent || second->parent->parent)
		return (binary_trees_ancestor(first->parent->parent->parent, second->parent->parent));
	else
		return (NULL);
}
