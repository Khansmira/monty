#include "monty.h"

/**
 * stack_node - adds a new node to stack_t stack
 * @stack: head
 * @n: constant int
 *
 * Return: new node or NULL on failure
 */
stack_t *stack_node(stack_t **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		return (NULL);
	}
	new->n = n;

	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;

	*stack = new;

	return (new);
}

/**
 * queue_node - adds a new node to stack_t queue
 * @stack: head
 * @n: number of nodes
 *
 * Return: new node or NULL on failure
 */
stack_t *queue_node(stack_t **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *current = *stack;

	if (!new)
	{
		free(new);
		return (NULL);
	}
	new->n = n;

	if (!*stack)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
		return (new);
	}

	while (current)
	{
		if (!current->next)
		{
			new->next = NULL;
			new->prev = current;
			current->next = new;
			break;
		}
		current = current->next;
	}

	return (new);
}


/**
 * print_stack - prints contents of stack_t
 * @stack: head
 *
 * Return: number of elements
 */
size_t print_stack(const stack_t *stack)
{
	size_t i = 0;

	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		i++;
	}

	return (i);
}
