#include "monty.h"

/**
 * addData_to_stack - Adds a new node to the stack.
 * @node: Pointer to the new node.
 * @line_no: Current line.
 * Return: Void.
 */

void addData_to_stack(stack_t **node, unsigned int line_no)
{
	stack_t *temp_node;
	(void)line_no;

	if (node == NULL || *node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *node;
		return;
	}

	temp_node = head;
	head = *node;
	head->next = temp_node;
	temp_node->prev = head;
}

/**
 * addData_to_queue - Adds a new node to the stack.
 * @node: Pointer to the new node.
 * @line_no: Current line.
 * Return: Void.
 */

void addData_to_queue(stack_t **node, unsigned int line_no)
{
	stack_t *temp_node;
	(void)line_no;

	if (node == NULL || *node == NULL)
	{
		exit(EXIT_FAILURE);
	}

	if (head == NULL)
	{
		head = *node;
		return;
	}
	temp_node = head;

	while (temp_node->next != NULL)
	{
		temp_node = temp_node->next;
	}

	temp_node->next = *node;
	(*node)->prev = temp_node;
}

/**
 * _printAll - Adds a new node to the stack.
 * @node: Pointer to the new node.
 * @line_no: Current line.
 * Return: Void.
 */

void _printAll(stack_t **node, __attribute__((unused))unsigned int line_no)
{
	stack_t *temp_node;

	if (node == NULL)
		exit(EXIT_FAILURE);
	temp_node = *node;
	while (temp_node != NULL)
	{
		printf("%d\n", temp_node->n);
		temp_node = temp_node->next;
	}
}

/**
 * _pint - Prints the node at the top of the stack.
 * @node: Pointer to the new node.
 * @line_no: Current line.
 * Return: Void.
 */

void _pint(stack_t **node, unsigned int line_no)
{
	if (node == NULL || *node == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_no);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*node)->n);
}


/**
 * _popNode - Adds a node to the stack.
 * @node: Pointer to the new node.
 * @line_no: Current line.
 * Return: Void.
 */

void _popNode(stack_t **node, unsigned int line_no)
{
	stack_t *temp_node;

	if (node == NULL || *node == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_no);
		exit(EXIT_FAILURE);
	}

	temp_node = *node;
	if (temp_node->next == NULL)
	{
		exit(EXIT_SUCCESS);
	}
	*node = temp_node->next;
	(*node)->prev = NULL;
	free(temp_node);
}


