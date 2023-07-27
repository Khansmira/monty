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
void push(stack_t **stack, unsigned int count)
{
	char *n = global.args;

	if ((int_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		exit(EXIT_FAILURE);
	}

	if (global.data_struct == 1)
	{
		if (!stack_node(stack, atoi(global.args)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!queue_node(stack, atoi(global.args)))
		{
			exit(EXIT_FAILURE);
		}
	}
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
	print_stack(*stack);
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
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_cnt);
		exit(EXIT_FAILURE);

	}
	printf("%d\n", (*stack)->n);
}


/**
 * int_digit - checks if a string is a digit
 * @str: string to check
 *
 * Return: 1 on success and 0 otherwise
 */
int int_digit(char *str)
{
	if (!str || *str == '\0')
	{
		return (0);
	}
	if (*str == '-')
	{
		str++;
	}
	while (*str)
	{
		if (isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}
