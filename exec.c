#include "monty.h"

/**
 * _readFd - Reads a file one line at a time.
 * @file: Pointter to the file.
 * Return: Void.
*/

void _readFd(FILE *file)
{
	char *buffer = NULL;
	size_t  len = 0;
	int format = 0, line_no = 1;

	while ((getline(&buffer, &len, file)) != -1)
	{
		format = _processLine(buffer, line_no, format, file);
		line_no++;
	}
	free(buffer);
}

/**
 * _processLine - Splits off two tokens from a line.
 * @buffer: Line to tokenize.
 * @line_no: Line number in file.
 * @format: 1 for Queue operations, 0 otherwise.
 * @file: Pointer to open file.
 * Return: Void
 */

int _processLine(char *buffer, int line_no, int format, FILE *file)
{
	char *opcode, *data;
	int status = 0;

	if (buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	opcode = strtok(buffer, DELIM);
	if (opcode == NULL)
		return (format);
	data = strtok(NULL, DELIM);
	data = data ? data : NULL;

	if (opcode[0] == '#')
		return (format);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	if (strcmp(opcode, "stack") == 0)
		return (0);

	status = _filterCommand(opcode, data, line_no, format);

	if (status == 5)
	{
		fclose(file);
		free(buffer);
		exit(1);
	}

	return (format);
}

/**
 * _filterCommand - Filters a list of functions
 * based on a match between the first token and first string
 * on the list.
 *
 * @opcode: Command to execute.
 * @data: Command argument.
 * @line_no: Line number in file.
 * @format: 1 for Queue operations, 0 otherwise.
 * Return: Void
 */

int _filterCommand(char *opcode, char *data, int line_no, int format)
{
	int i;

	instruction_t funcTrigger[] = {
	{"push", addData_to_stack},
	{"pall", _printAll},
	{"pint", _pint},
	{"pop", _popNode},
	{"swap", _swapNodes},
	{"add", _addNode},
	{"nop", _nop},
	{"sub", _subtractNodes},
	{"div", _divideNodes},
	{"mul", _mul},
	{"mod", _mod},
	{"pchar", _printChar},
	{"pstr", _printStr},
	{"rotl", _rotl},
	{"rotr", _rotr},
	{NULL, NULL},
	};

	i = 0;
	while (funcTrigger[i].opcode != NULL)
	{
		if (strcmp(opcode, funcTrigger[i].opcode) == 0)
		{
			_triggerFunc(funcTrigger[i].f, opcode, data, line_no, format);
			if (strcmp(opcode, "pchar") == 0)
			{
				if (head == NULL)
					return (5);
			}
			return (0);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_no, opcode);
	exit(EXIT_FAILURE);
	return (0);
}

/**
 * _triggerFunc - Calls a specific function
 * @f: Pointer to the called function.
 * @opcode: Command string.
 * @data: Value to be pushed
 * @line_no: Line number in file.
 * @format: 1 for Queue operations, 0 otherwise.
 * Return: Void
 */

void _triggerFunc(triggeredFunc f, char *opcode,
		char *data, int line_no, int format)
{
	int i = 0, sign_flag = 1;
	stack_t *node;

	if (strcmp("push", opcode) == 0)
	{
		if (line_no == 1)
			head = NULL;
		if (data == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_no);
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
				fprintf(stderr, "L%d: usage: push integer\n", line_no);
				exit(EXIT_FAILURE);
			}
			i++;
		}

		node = _generateNode(data, sign_flag);
		if (format == 1)
			addData_to_queue(&node, line_no);
		if (format == 0)
			f(&node, line_no);
	}
	else
	{
		f(&head, line_no);
	}

}
