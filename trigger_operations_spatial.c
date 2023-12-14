#include "monty.h"

/**
 * _rotl - Rotates the nodes so the top becomes last and second top.
 * @node: Pointer to a head node.
 * @line_no: Current line.
 * Return: Void.
 */

void _rotl(stack_t **node, __attribute__((unused))unsigned int line_no)
{
	stack_t *temp_node;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
	{
		return;
	}

	temp_node = *node;
	while (temp_node->next != NULL)
	{
		temp_node = temp_node->next;
	}

	temp_node->next = *node;
	(*node)->prev = temp_node;
	*node = (*node)->next;
	(*node)->prev->next = NULL;
	(*node)->prev = NULL;
}

/**
 * _rotr - Rotates the nodes so the top becomes last and second top.
 * @node: Pointer to a head node.
 * @line_no: Current line.
 * Return: Void.
 */

void _rotr(stack_t **node, __attribute__((unused))unsigned int line_no)
{
	stack_t *temp_node;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
	{
		return;
	}

	temp_node = *node;
	while (temp_node->next != NULL)
	{
		temp_node = temp_node->next;
	}

	temp_node->next = *node;
	temp_node->prev->next = NULL;
	temp_node->prev = NULL;
	(*node)->prev = temp_node;
	(*node) = temp_node;
}

/**
 * _generateNode - Creates a node and initializes itts data value.
 *
 * @data: Data to inittialise with.i
 * @sign-flag: Positive or negative flag.
 * Return: A node
 */

stack_t *_generateNode(char *data, int sign_flag)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = (atoi(data) * sign_flag);
	node->next = NULL;
	node->prev = NULL;

	return (node);
}
