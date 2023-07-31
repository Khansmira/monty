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
int main(int argc, char *argv[])
{
	char opcode[6] = {0}, buf[1024] = {0};
	ssize_t read;
	size_t len;
	stack_t *stack = NULL;
	int matches = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	globes.fm = NULL;
	globes.fm = fopen(argv[1], "r");
	if (globes.fm == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		fclose(globes.fm);
		exit(EXIT_FAILURE);
	}
	globes.lineptr = NULL;
	while ((read = getline(&globes.lineptr, &len, globes.fm)) != -1)
	{
		line_number++;
		if (!_iswhitespace())
		{
			matches = sscanf(globes.lineptr, "%s%d%1s", opcode, &globes.data, buf);
			if (matches != 2 && strcmp(opcode, "push") == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit_free(stack);
				exit(EXIT_FAILURE);
			}
			if (opcode != NULL && opcode[0] != '#')
				opc(&stack, line_number, opcode);
		}
		free(globes.lineptr);
		globes.lineptr = NULL;
	}
	exit_free(stack);
	return (0);
}



/**
 * free_stack - frees a dlistint_t linked list
 * @stack: list head
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

/**
 * exit_free - frees all possible allocs before exiting the program
 * @stack: ptr to a stack
 * Return: void
 */
void exit_free(stack_t *stack)
{
	fclose(globes.fm);
	if (globes.lineptr != NULL)
		free(globes.lineptr);
	free_stack(stack);
}


/**
 * _iswhitespace - check for whitespace
 *
 * Return: 1 if only whitespace 0 if not only whitespace
 */
int _iswhitespace(void)
{
	int i, j;
	char *ws = "\r\n\t ";

	for (i = 0; globes.lineptr[i] != '\0'; i++)
		for (j = 0; ws[j] != '\0' && ws[j] != globes.lineptr[i]; j++)
			if (ws[j] == '\n')
				return (0);
	return (1);
}
