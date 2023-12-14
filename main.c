#include "monty.h"

stack_t *head = NULL; 
/**
 * main - Program entry point.
 * @argc: Number of arguments.
 * @argv: Array of arguments.%s/\s\+$//e
 * Return: Always 0.
*/

int main(int argc, char **argv)
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	_readFd(file);

	fclose(file);

	_clear();
	return (0);
}
