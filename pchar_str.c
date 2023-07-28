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
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*stack)->n) > 127 || ((*stack)->n) < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		exit(EXIT_FAILURE);
		return;
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
	stack_t *s = *stack;

	while (s)
	{
		if (s->n <= 0 || c->n > 127)
			break;
		putchar((char) s->n);
		s->next = s;
		s = s->next;
	}
	putchar('\n');
}


