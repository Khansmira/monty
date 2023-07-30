#include "monty.h"

/**
 * opcode - selects the correct opcode to perform
 * @stack: stack double pointer
 * @count: line number
 *
 * Return: void
 */
void opcode(stack_t **stack, char *str, unsigned int count)
{
	int i = 0;

	instruction_t instruct[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", op_add},
		{"nop", nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (!_strcmp(str, "stack"))
	{
		global.data_struct = 1;
		return;
	}
	if (!_strcmp(str, "queue"))
	{
		global.data_struct = 0;
		return;
	}

	while (instruct[i].opcode)
	{
		if (_strcmp(instruct[i].opcode, str) == 0)
		{
			instruct[i].f(stack, count);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", count, str);
	exit(EXIT_FAILURE);
}
