#include "monty.h"

/**
 * _readFd - Reads a file one line at a time.
 * @file: Pointter to the file.
 * Return: Void.
*/

void _readFd(FILE *file)
{
	char *buffer = NULL;
	size_t  len = 0, line_num = 1;
	int format = 0;

	while ((getline(&buffer, &len, file)) != -1)
	{
		format = _processLine(buffer, line_num, format);
		line_num++;
	}
}

/**
 * _processLine - Splits off two tokens from a line.
 * @buffer: Line to tokenize.
 * @line_num: Line number in file.
 * Return: Void
 */

int _processLine(char *buffer, size_t line_num, int format)
{
	char *opcode, *data;

	if (buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	opcode = strtok(buffer, DELIM);
	if (opcode == NULL)
		return (format);
	data = strtok(NULL, DELIM);

	if (opcode[0] == '#')
		return (format);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	if (strcmp(opcode, "stack") == 0)
		return (0);

	_filterCommand(opcode, data, line_num, format);
	
	return (format);
}

/**
 * _filterCommand - Filters a list of functions
 * based on a match between the first token and first string
 * on the list.
 *
 * @buffer: Line to tokenize.
 * @line_num: Line number in file.
 * Return: Void
 */

void _filterCommand(char *opcode, char *data, size_t line_num, int format)
{
	int i;

	instruction_t funcTrigger[] = {
	{"push", addData_to_stack},
	{"pall", _printAll},
	{"pint", _pint},
	{"pop", _popNode},
	{"swap", _swapNodes},
	{"add", _addNode},
	{NULL, NULL}
	};
	/*{"nop", nop},
	{"sub", _subtractNodes},
	{"div", _divideNodes},
	{"mul", _mul},
	{"mod", _mod},
	{"pchart", _printChart},
	{"pstr", _printStr},
	{"rotl", print_top},
	{"rotr", print_top},
	{NULL, NULL},
	};*/

	for (i = 0; funcTrigger[i].opcode != NULL; i++)
	{
		_triggerFunc(funcTrigger[i].f, opcode, data, line_num, format);
		return;	
	}
	/*while (funcTrigger[i].opcode != NULL)
	{
		printf("opcode 2-: %s\n", opcode);
		if (strcmp(opcode, funcTrigger[i].opcode) == 0)
		{
			_triggerFunc(funcTrigger[i].f, opcode, data, line_num, format);
			return;
		}
		i++;
	}*/
}

/**
 * _triggerFunc - Calls a specific function
 * @f: Pointer to the called function.
 * @opcode: Command string.
 * @data: Value to be pushed
 * @line_num: Line number in file.
 * Return: Void
 */

void _triggerFunc(triggeredFunc f, char *opcode, char *data, int line_num, int format)
{
	int i = 0, sign_flag = 1;
	stack_t *node;

	if (strcmp("push", opcode) == 0)
	{
		if (data == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}

		if (data != NULL && data[0] == '-')
		{
			data = data + 1;
			sign_flag = -1;
		}

		while (data[i] != '\0')
		{
			if (isdigit(data[i]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_num);
				exit(EXIT_FAILURE);
			}
			i++;
		}

		if (format == 1)
		{
			addData_to_queue(&node, line_num);
		}
		else
		{
			f(&node, line_num);
		}
	}
	else
		printf("Execute function normally\n");
		/*f(&head, line_num);*/

	printf("Flag: %d\n ", sign_flag);
}

void bruhh(void)
{
	printf("works bitch!!!!\n");
}

void addData_to_stack(__attribute__((unused))stack_t **node, __attribute__((unused))unsigned int ln)
{
	printf("AddData to stack works!\n");
}

void addData_to_queue(__attribute__((unused))stack_t **new_node, __attribute__((unused))unsigned int ln)
{
        printf("AddData to queue works!\n");
}

void _printAll(__attribute__((unused))stack_t **new_node, __attribute__((unused))unsigned int ln)
{
        printf("_printAll to stack works!1\n");
}

void _pint(__attribute__((unused))stack_t **new_node, __attribute__((unused))unsigned int ln)
{
        printf("_pint to stack works!2");
}

void _popNode(__attribute__((unused))stack_t **new_node, __attribute__((unused))unsigned int ln)
{
        printf("_swapNodes to stack works!3");
}

void _swapNodes(__attribute__((unused))stack_t **new_node, __attribute__((unused))unsigned int ln)
{
        printf("_swapNodes to stack works!4");
}

void _addNode(__attribute__((unused))stack_t **new_node, __attribute__((unused))unsigned int ln)
{
        printf("AddNode to stack works!5");
}
