#include "monty.h"

/**
* rotl - rotates the top and second element in the stack
* @stack: stack double pointer
* @count: line number
*
* Return: void
*/
void rotl(stack_t **stack, unsigned int count)
{
	stack_t *a;
	stack_t *b;

	(void) count;
	if (!stack || !*stack || !(*stack)->next)
		return;

	a = b = *stack;

	while (a->next != NULL)
		a = a->next;

	b->next = b;
	*stack->prev = b;
	*stack = a->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}



/**
* rotr - rotates the last element of a stack_t stack to the top
* @stack: stack double pointer
* @count: line number of opcode
*
* Return: void
*/
void rotr(stack_t **stack, unsigned int count)
{
	stack_t *lt;
	stack_t *rt;

	(void) count;
	if (!stack || !*stack || !(*stack)->next)
		return;

	lt = *stack;

	while (lt->next != NULL)
		lt = lt->next;

	rt = lt->prev;
	lt->next = *stack;
	(*stack)->prev = lt;
	*stack = lt;
	(*stack)->prev = NULL;
        rt->next = NULL;
}
