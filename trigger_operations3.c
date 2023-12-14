#include "monty.h"

/**
 * _mul - Multiplies the data in the top two nodes in the stack.
 * @node: Pointer to a head node.
 * @line_number: Current line.
 * Return: Void.
 */

void _mul(stack_t **node, unsigned int ln)
{
	int total;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
	{
		 fprintf(stderr, "L%d: can't mul, stack too short\n", ln);
		 exit(EXIT_FAILURE);
	}

	(*node) = (*node)->next;
	total = (*node)->n * (*node)->prev->n;
	(*node)->n = total;
	free((*node)->prev);
	(*node)->prev = NULL;
}

/**
 * _mod - Finds the modulo between the data in
 * the top two nodes in the stack.
 *
 * @node: Pointer to head node.
 * @line_number: Current line.
 * Return: Void.
 */

void _mod(stack_t **node, unsigned int ln)
{
        int total;

        if (node == NULL || *node == NULL || (*node)->next == NULL)
        {
                fprintf(stderr, "L%d: can't mod, stack too short\n", ln);
                exit(EXIT_FAILURE);
        }

	if ((*node)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln);
		exit(EXIT_FAILURE);
	}

	(*node) = (*node)->next;
	total = (*node)->n % (*node)->prev->n;
	(*node)->n = total;
	free((*node)->prev);
	(*node)->prev = NULL;
}


/**
 * _printChar - Prints the ascii value of the head node data.
 * @node: Pointer to head node.
 * @line_number: Current line.
 * Return: Void.
 */

void _printChar(stack_t **node, unsigned int ln)
{       
        int value;
        
        if (node == NULL || *node == NULL)
        {       
                fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
                exit(EXIT_FAILURE);
        }

	 value = (*node)->n;
	 if (value < 0 || value > 225)
	 {
		 fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
		 exit(EXIT_FAILURE);
	 }

	 printf("%c\n", value);
}

/**
 * _printStr - Prints a sttring using the ascii values of the
 * node data starting from the head node.
 *
 * @node: Pointer to head node.
 * @line_number: Current line.
 * Return: Void.
 */

void _printStr(stack_t **node, __attribute__((unused))unsigned int ln)
{
        int value;
	stack_t *temp_node;

        if (node == NULL || *node == NULL)
        {
		printf("\n");
		return;
        }

	temp_node = *node;

	while (temp_node != NULL)
	{
		value = temp_node->n;

		if (value <= 0 || value > 255)
			break;
		printf("%c", value);
		temp_node = temp_node->next;
	}

	printf("\n");
}

/**
 * _clear - Clears the list by freeing each node.
 * Return: Void.
 */

void _clear(void)
{
	stack_t *temp_node;

	if (head == NULL)
		return;
	while (head !=  NULL)
	{
		temp_node = head;
		head = head->next;

		free(temp_node);
	}
}
