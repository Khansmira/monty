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
	stack_t *tmp = *stack;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
	if (tmp->next == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
}



/**
 * swap -  swaps elements between the top two elements on the stack
 * @stack: stack
 * @count: number of lines
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int count)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

