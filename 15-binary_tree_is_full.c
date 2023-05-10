#include "binary_trees.h"

int is_full_recursive(const binary_tree_t *tree);

/**
 * binary_tree_is_full - Write a function that checks if a binary tree is full
 *
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, your function must return 0
*/

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_full_recursive(tree));
}

/**
 * is_full_recursive - Function to verify if tree us fully recursive
 *
 * @tree: Pointer to the head of the tree
 *
 * Return: Exit with 1 for full else 0
*/

int is_full_recursive(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if (((tree->left != NULL) && (tree->right == NULL)) ||
		   ((tree->left == NULL) && (tree->right != NULL)) ||
		   (is_full_recursive(tree->left) == 0) ||
		   (is_full_recursive(tree->right) == 0))
			return (0);
	}

	return (1);
}
