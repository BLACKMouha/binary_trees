#include "binary_trees.h"
#include <stdio.h>

int sbinary_tree_depth(const binary_tree_t *tree);

binary_tree_t *same_depth_ancestor(
	const binary_tree_t *first,
	const binary_tree_t *second);

binary_tree_t *deeper_depths_ancestor(
	const binary_tree_t *first,
	const binary_tree_t *second);

binary_tree_t *shallower_depths_ancestor(
	const binary_tree_t *first,
	const binary_tree_t *second);
/**
 * sbinary_tree_depth - measures the depth of a node in a binary tree
 * Prototype: size_t binary_tree_depth(const binary_tree_t *tree);
 * @tree: pointer to the root node of the tree to measure the depth
 * Return: the number of levels from root to a specific node.
 * If the binary tree does not exist, -1 is returned
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
	int df = sbinary_tree_depth(first);
	int ds = sbinary_tree_depth(second);
	binary_tree_t *f, *s;

	if (df == -1 && ds == -1)
		return (NULL);
	f = (binary_tree_t *)first;
	s = (binary_tree_t *)second;

	if (df == 0 && ds == 0)
		return (f);
	else if (df == 0 && ds == -1)
		return (f);
	else if (df == -1 && ds == 0)
		return (s);
	else if (df >= 0 && ds < 0)
		return (f);
	else if (df < 0 && ds >= 0)
		return (s);

	else if (df > 0 && ds > 0 && df == ds)
		return (same_depth_ancestor(f, s));

	else if (df > 0 && ds > 0 && df != ds)
	{
		if (df > ds)
			return (deeper_depths_ancestor(f, s));
		if (df < ds)
			return (shallower_depths_ancestor(f, s));
	}
	return (NULL);
}

/**
 * same_depth_ancestor - finds the lowest common ancestor of two nodes at same
 * level
 *
 * Prototype: binary_tree_t *same_depth_ancestor(
 *                              const binary_tree_t *first,
 *                              const binary_tree_t *second);
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 * if it exists, otherwise NULL
 */
binary_tree_t *same_depth_ancestor(
	const binary_tree_t *first,
	const binary_tree_t *second)
{
	int df = sbinary_tree_depth(first);
	int ds = sbinary_tree_depth(second);
	binary_tree_t *f, *s;

	if (df == -1 && ds == -1)
		return (NULL);
	f = (binary_tree_t *) first;
	s = (binary_tree_t *) second;

	if (df > 0 && ds > 0 && df == ds)
	{
		if (f == s)
			return (f);
		if (f != s)
		{
			if (f->parent == s->parent)
				return (f->parent);
			while (f->parent && s->parent)
			{
				if (f->parent == s->parent)
					return (f);
				f = f->parent;
				s = s->parent;
			}
			return (f);
		}
	}
	return (NULL);
}

/**
 * deeper_depths_ancestor - finds the lowest common ancestor of two nodes where
 * the first is deeper
 *
 * Prototype: binary_tree_t *deeper_depths_ancestor(
 *                              const binary_tree_t *deep,
 *                              const binary_tree_t *shalow);
 * @deep: pointer to the deepest node
 * @shallow: pointer to the shallowest node
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 * if it exists, otherwise NULL
 */
binary_tree_t *deeper_depths_ancestor(
	const binary_tree_t *deep,
	const binary_tree_t *shallow)
{
	int dd = sbinary_tree_depth(deep);
	int ds = sbinary_tree_depth(shallow);
	binary_tree_t *d, *s;

	if (dd == -1 && ds == -1)
		return (NULL);
	d = (binary_tree_t *) deep;
	s = (binary_tree_t *) shallow;

	if (dd > ds)
	{
		while (dd != ds)
		{
			d = d->parent;
			if (binary_tree_sibling(d) == s)
				return (d->parent);
			dd--;
		}
		if (d == s)
			return (d);
		while (d)
		{
			if (d->parent == s->parent)
				return (d->parent);
			d = d->parent;
			s = s->parent;
		}
		return (d);
	}
	return (NULL);
}

/**
 * shallower_depths_ancestor - finds the lowest common ancestor of two nodes
 * where the first is shallower
 *
 * Prototype: binary_tree_t *shallower_depths_ancestor(
 *                              const binary_tree_t *deep,
 *                              const binary_tree_t *shalow);
 * @deep: pointer to the deepest node
 * @shallow: pointer to the shallowest node
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 * if it exists, otherwise NULL
 */
binary_tree_t *shallower_depths_ancestor(
	const binary_tree_t *deep,
	const binary_tree_t *shallow)
{
	int dd = sbinary_tree_depth(deep);
	int ds = sbinary_tree_depth(shallow);
	binary_tree_t *d, *s;

	if (dd == -1 && ds == -1)
		return (NULL);
	d = (binary_tree_t *) deep;
	s = (binary_tree_t *) shallow;

	if (dd < ds)
	{
		while (dd != ds)
		{
			s = s->parent;
			if (binary_tree_sibling(s) == d)
				return (d->parent);
			ds--;
		}
		if (d == s)
			return (d);
		while (s)
		{
			if (s->parent == d->parent)
				return (s->parent);
			d = d->parent;
			s = s->parent;
		}
		return (s);
	}
	return (NULL);
}
