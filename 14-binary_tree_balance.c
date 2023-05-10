#include "binary_trees.h"

/**
 * binary_tree_balance - Write a function that measures the balance factor
 * of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the balance
 * factor
 *
 * Return: If tree is NULL, return 0
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return  (0);
}


/**
 * binary_tree_height - Function to find the height of the binary tree
 *
 * @tree: Pointer to the root of the tree
 *
 * Return: Exit with result else 0
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left = 0;
		size_t right = 0;

		left = tree->left ? binary_tree_height(tree->left) + 1 : 1;
		right = tree->right ? binary_tree_height(tree->right) + 1 : 1;

		return ((left > right ? left : right));
	}

	return (0);
}
