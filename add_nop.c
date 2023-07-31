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
	int a, b;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = a + b;
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

