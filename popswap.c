#include <ctype.h>
#include <string.h>
#include "monty.h"

/**
* pop - removes the top element of the stack
* @stack: stack
* @count: number of lines
*
* Return: void
*/
void pop(stack_t **stack, unsigned int count)
{
	stack_t *s = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", count);
		exit(EXIT_FAILURE);
	}

	*stack = s;
	s = (*stack)->next;
	free(*stack);
	if (!*stack)
		return;
	(*stack)->prev = NULL;

	free(s);
}



/**
 * swap -  swaps elements between the top 2 on the stack
 * @stack: stack
 * @count: number of lines
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int count)
{
	stack_t *s = NULL;
	int i = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", count);
		exit(EXIT_FAILURE);
	}
	s = *stack;
	i  = s->n;

	s->n = s->next->n;
	s->next->n = i;
}
