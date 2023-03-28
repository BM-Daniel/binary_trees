#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_node - Write a function that creates a binary tree node
 *
 * @parent: a pointer to the parent node of the node to create
 * @value: the value to put in the new node
 *
 * Return: A pointer to the new node or NULL on failure
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *ptr = malloc(sizeof(binary_tree_t));

	if (ptr == NULL)
		return;

	ptr->n = value;
	ptr->left = NULL;
	ptr->right = NULL;
	ptr->parent = parent;

	return (ptr);
}
