#include <string.h>
#include "monty.h"

/**
 * pchar - prints character at the top of stack
 * @stack: stack double pointer
 * @count: line number
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int count)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}


/**
 * pstr - prints a string at tje top of the stack
 * @stack: stack double pointer
 * @count: line number
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int count __attribute__((unused)))
{
	stack_t *tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->n <= 0 || tmp->n > 127)
			break;
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
