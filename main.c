#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * main - Entry point of the Monty interpreter.
 * @argc: Number of arguments passed to the program.
 * @argv: Array of pointers to the arguments.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		return (EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL; /* Initialize stack */

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		char *opcode = strtok(line, " \t\n");
		char *argument = strtok(NULL, " \t\n");

		if (opcode != NULL && opcode[0] != '#')
		{
			if (strcmp(opcode, "push") == 0)
			{
				if (argument == NULL)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					return (EXIT_FAILURE);
				}
				int value = atoi(argument);
				if (value == 0 && strcmp(argument, "0") != 0)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					return (EXIT_FAILURE);
				}
				push(&stack, value, line_number);
			}
			else if (strcmp(opcode, "pall") == 0)
			{
				pall(&stack, line_number);
			}
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				return (EXIT_FAILURE);
			}
		}
	}

	free(line);
	fclose(file);

	return (EXIT_SUCCESS);
}
