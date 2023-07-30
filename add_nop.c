#include <ctype.h>
#include <string.h>
#include "monty.h"

/**
 * op_add -  adds the top two nodes of the stack
 * @stack: stack double pointer
 * @count: line number of opcode
 *
 * Return: void
 */
void op_add(stack_t **stack, unsigned int count)
{
	int s;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		exit(EXIT_FAILURE);
	}

	s = ((*stack)->next->n) + ((*stack)->n);
	(*stack)->n = s;
	pop(stack, count);
}

/**
 * nop - this does nothing
 * @stack: void
 * @count : void
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int count)
{
	(void) stack;
	(void) count;
}

