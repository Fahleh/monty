#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#define DELIM " \t$\n"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef void (*triggeredFunc)(stack_t **, unsigned int);
extern stack_t *head;

void bruhh(void);
	/* ======= UTILS ======= */
void _readFd(FILE *file);
int _processLine(char *buffer, size_t line_num, int format);
void _filterCommand(char *opcode, char *data, size_t line_num, int format);
void _triggerFunc(triggeredFunc, char *, char *, int, int);

	/* ======= OPERATIONS ======= */
void addData_to_stack(stack_t **node, __attribute__((unused))unsigned int ln);
void addData_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln);

void _printAll(stack_t **new_node, __attribute__((unused))unsigned int ln);
void _pint(stack_t **new_node, __attribute__((unused))unsigned int ln);
void _popNode(stack_t **new_node, __attribute__((unused))unsigned int ln);
void _swapNodes(stack_t **new_node, __attribute__((unused))unsigned int ln);
void _addNode(stack_t **new_node, __attribute__((unused))unsigned int ln);


#endif
