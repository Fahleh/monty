#include "monty.h"

/**
 * _swapNodes - Swaps the top two nodes of the stack.
 * @node: Pointer to a head node.
 * @line_number: Current line.
 * Return: Void.
 */

void _swapNodes(stack_t **node, unsigned int ln)
{
        stack_t *temp_node;

        if (node == NULL || *node == NULL || (*node)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
	       exit(EXIT_FAILURE);
	}

	temp_node = (*node)->next;
	(*node)->next = temp_node->next;

	if (temp_node->next != NULL)
		temp_node->next->prev = *node;
	temp_node->next = *node;
	(*node)->prev = temp_node;
	temp_node->prev = NULL;
	*node = temp_node;
}

/**
 * _addNode - Adds the data in the top two nodes in the stack.
 * @node: Pointer to head node.
 * @line_number: Current line.
 * Return: Void.
 */

void _addNode(stack_t **node, unsigned int ln)
{
	int total;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	(*node) = (*node)->next;
	total = (*node)->n + (*node)->prev->n;
	(*node)->n = total;
	free((*node)->prev);
	(*node)->prev = NULL;
}

/**
 * _nop - A function that doesen't do anything.
 * @node: Pointer to head node.
 * @line_number: Current line.
 * Return: Void.
 */

void _nop(__attribute__((unused))stack_t **node, __attribute__((unused))unsigned int ln)
{
	return;
}

/**
 * _subtractNodes -- Subtracts the data in the top two nodes in the stack.
 * @node: Pointer to the head node.
 * @line_number: Current line.
 * Return: Void.
 */

void _subtractNodes(stack_t **node, unsigned int ln)
{
	int total;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	(*node) = (*node)->next;
	total = (*node)->n - (*node)->prev->n;
	(*node)->n = total;
	free((*node)->prev);
	(*node)->prev = NULL;
}


/**
 * _divideNodes - Divides the data in the top two nodes in the stack.
 * @node: Pointer to the head node.
 * @line_number: Current line.
 * Return: Void.
 */

void _divideNodes(stack_t **node, unsigned int ln)
{
	int total;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
	{

		fprintf(stderr, "L%d: can't div, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	if((*node)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln);
		exit(EXIT_FAILURE);
	}

	(*node) = (*node)->next;
	total = (*node)->n / (*node)->prev->n;
	(*node)->n = total;
	free((*node)->prev);
	(*node)->prev = NULL;
}



