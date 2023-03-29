#include "binary_trees.h"
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
	f = (binary_tree_t*)first;
	s = (binary_tree_t*)second;

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
	{
		if (f == s)
			return (f);
		if (f != s)
		{
			if (f->parent == s->parent)
				return (f->parent);
			while (f && s)
			{
				if (f->parent == s->parent)
					return (f);
				f = f->parent;
				s = s->parent;
			}
		}
	}

	else if (df > 0 && ds > 0 && df != ds)
	{
		if (df > ds)
		{
			while (df != ds)
			{
				f = f->parent;
				if (binary_tree_sibling(f) == s)
					return (f->parent);
				df--;
			}
			if (f == s)
				return (f);
			while (f && s)
			{
				if (f->parent == s->parent)
					return (f);
				f = f->parent;
				s = s->parent;
			}
			return (f);
		}
		if (df < ds)
		{
			while (df != ds)
			{
				s = s->parent;
				if (binary_tree_sibling(s) == f)
					return (s->parent);
				ds--;
			}
			if (f == s)
				return (f);
			while (f && s)
			{
				if (f->parent == s->parent)
					return (f);
				f = f->parent;
				s = s->parent;
			}
		}
	}
	return (NULL);
}
