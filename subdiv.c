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
	int s;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		exit(EXIT_FAILURE);
	}

	s = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, count);
	(*stack)->n = s;
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
	int s;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", count);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		exit(EXIT_FAILURE);
	}
		
		return;

	s = ((*stack)->next->n) / ((*stack)->n);
	pop(stack, count);
	(*stack)->n = s;
}
