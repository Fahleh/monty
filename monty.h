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
	void (*f)(stack_t **stack, unsigned int line_no);
} instruction_t;

extern stack_t *head;
typedef void (*triggeredFunc)(stack_t **, unsigned int);


	/* ======= EXECUTION ======= */
void _readFd(FILE *file);
int _processLine(char *buffer, size_t line_num, int format);
void _filterCommand(char *opcode, char *data, size_t line_no, int format);
void _triggerFunc(triggeredFunc, char *, char *, int, int);



	/* ======= OPERATIONS-> triggerFunc ======= */
void addData_to_stack(stack_t **node, unsigned int line_no);
void addData_to_queue(stack_t **node, unsigned int line_no);
void _printAll(stack_t **node, __attribute__((unused))unsigned int line_no);
void _pint(stack_t **node, unsigned int line_no);
void _popNode(stack_t **node, unsigned int line_no);



	/* ======= OPERATIONS-> triggerFunc2 ======= */
void _swapNodes(stack_t **node, unsigned int line_no);
void _addNode(stack_t **nnode, unsigned int ln);
void _nop(__attribute__((unused))stack_t **new_node, unsigned int line_no);
void _subtractNodes(stack_t **new_node, unsigned int line_no);
void _divideNodes(stack_t **new_node, unsigned int line_no);



	/* ======= OPERATIONS-> triggerFunc3 ======= */
void _mul(stack_t **new_node, unsigned int line_no);
void _mod(stack_t **new_node, unsigned int line_no);
void _printChar(stack_t **new_node, unsigned int line_no);
void _printStr(stack_t **new_node, unsigned int line_no);
void _clear(void);


	/* ======= OPERATIONS_SPATIAL ======= */
void _rotl(stack_t **new_node, __attribute__((unused))unsigned int line_no);
void _rotr(stack_t **new_node, __attribute__((unused))unsigned int line_no);
stack_t *_generateNode(char *data, int sign_flag);

#endif
