#include "monty.h"
#include <string.h>
/**
 * opc - selects the correct opcode to perform
 * @stack: stack double pointer
 * @line_number: line number of opcode selected
 * @opcode: the string from getline
 *
 * Return: void
 */
void opc(stack_t **stack,  unsigned int line_number, char *opcode)
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
	while (instruct[i].opcode != NULL)
	{
		if (strcmp(opcode, instruct[i].opcode) == 0)
		{
			instruct[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit_free(*stack);
	exit(EXIT_FAILURE);
}


