#include <ctype.h>
#include <string.h>
#include "monty.h"

/**
 * op_sub -  subtracts the first element from the
 * second element of the stack
 * @stack: stack double pointer
 * @count: line number
 *
 * Return: void
 */
void op_sub(stack_t **stack, unsigned int count)
{
	int a, b;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = b - a;
}

/**
 * op_div - divides thsecond element by the
 * top element of the stack
 * @stack: stack double pointer
 * @count: line number 
 *
 * Return: void
 */
void op_div(stack_t **stack, unsigned int count)
{
	int a, b;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
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
	(*stack)->n = b / a;
}
