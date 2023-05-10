#include "binary_trees.h"


unsigned char is_leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);


/**
 * binary_tree_is_perfect - Write a function that checks if a binary
 * tree is perfect
 *
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, your function must return 0
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}


/**
 * is_leaf - Function to verify if node is a leaf
 *
 * @node: Pointer to node
 *
 * Return: 1 if node is a leaf else 0
*/

unsigned char is_leaf(const binary_tree_t *node)
{
	return (((node->left == NULL) && (node->right == NULL)) ? 1 : 0);
}

/**
 * depth - Function to check depth of a node
 *
 * @tree: Pointer to node
 *
 * Return: The depth of node
*/

size_t depth(const binary_tree_t *tree)
{
	return ((tree->parent == NULL) ? 0 : depth(tree->parent) + 1);
}

/**
 * get_leaf - Function to return leaf
 *
 * @tree: Pointer to node
 *
 * Return: A pointer to first leave
*/

const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);

	return ((tree->right) ? get_leaf(tree->right) : get_leaf(tree->left));
}

/**
 * is_perfect_recursive - Function to check if tree is recursive
 *
 * @tree: Pointer to head of node
 * @leaf_depth: The depth of a leaf in a tree
 * @level: Level of the node
 *
 * Return: 1 if perfect else 0
*/

int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return ((level == leaf_depth) ? 1 : 0);

	if ((tree->left == NULL) || (tree->right == NULL))
		return (0);

	return ((is_perfect_recursive(tree->right, leaf_depth, (level + 1))) &&
	       (is_perfect_recursive(tree->left, leaf_depth, (level + 1))));
}
