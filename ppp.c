#include <ctype.h>
#include <string.h>
#include "monty.h"

/**
 * push - push element to the stack
 * @stack: stack given by main
 * @count: number of lines
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int count __attribute__((unused)))
{
	stack_t *tmp = *stack;

	tmp = malloc(sizeof(stack_t));
	if (tmp == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
	tmp->n = globes.data;
	tmp->prev = NULL;
	tmp->next = NULL;
	if (*stack != NULL)
	{
		tmp->next = *stack;
		(*stack)->prev = tmp;
	}
	*stack = tmp;
}


/**
 * pall - prints the stack
 * @stack: stack
 * @count: amount of lines
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int count __attribute__((unused)))
{
	stack_t *tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}


/**
 * pint - prints the value at the top of the stack
 * @stack:stack
 * @count: count of lines
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int count)
{
	stack_t *tmp = *stack;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", count);
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}
