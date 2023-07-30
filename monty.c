#define  _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <string.h>
#include <stdio.h>

/**
 * main - entry point
 * @argv: Monty arguments passed to program
 * @argc: total amount of arguments
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *buffer = NULL;
        char *str = NULL;
        stack_t *stack = NULL;
        unsigned int c = 1;
	size_t len = 0;
	int stat = 0;

	global.data_struct = 1;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while ((getline(&buffer, &len, file)) != (-1))
	{
		if (stat)
			break;
		if (*buffer == '\n')
		{
			c++;
			continue;
		}
		str = strtok(buffer, " \t\n");
		if (!str || *str == '#')
		{
			c++;
			continue;
		}
		global.args = strtok(NULL, " \t\n");
		opcode(&stack, str, c);
		c++;
	}
	free(buffer);
	free_stack(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}


/**
 * free_stack - frees a dlistint_t linked list
 * @stack: list head
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	if (stack)
	{
		next = stack->next;
		while (current)
		{
			free(current);
			current = next;
			if (next)
				next = next->next;
		}
	}
}

