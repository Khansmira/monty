#include <ctype.h>
#include <string.h>
#include "monty.h"

/**
 * mul - multiplies the second top node by the top node of the stack
 * @stack: stack double pointer
 * @count: line number of opcode
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int count)
{
	int s;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", count);
		exit(EXIT_FAILURE);
		return;
	}

	s = ((*stack)->next->n) * ((*stack)->n);
	pop(stack, count);
	(*stack)->n = s;
}



/**
 * mod - handles compiling modulus of secomd top and top element
 * @stack: stack double pointer
 * @count: line number of opcode
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int count)
{
	int s;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		exit(EXIT_FAILURE);
		return;
	}

	s = ((*stack)->next->n) % ((*stack)->n);
	pop(stack, count);
	(*stack)->n = s;
}
