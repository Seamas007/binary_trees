#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_right - insert the node at the right child
 * @parent: pointer to the node to insert the left child in
 * @value: value to store in the new node
 *
 * Return: the pointer to the created node or NULL in failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node_inserted;

	node_inserted = (binary_tree_t *)malloc(sizeof(binary_tree_t));
	if (node_inserted == NULL || parent == NULL || value == '\0')
		return (NULL);

	node_inserted->parent = parent;
	node_inserted->n = value;
	node_inserted->left = NULL;
	if (parent->right != NULL)
	{
		node_inserted->right = parent->right;
		node_inserted->right->parent = node_inserted;
		parent->right = node_inserted;
	}
	else
	{
		node_inserted->right = NULL;
		parent->right = node_inserted;
	}
	return (node_inserted);
}
