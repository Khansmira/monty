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
	int a, b;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = b * a;
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
	int a, b;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	if (a == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
	b = (*stack)->next->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = b % a;
}
