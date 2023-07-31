#include "monty.h"

/**
* rotl - rotates the top and second element in the stack
* @stack: stack double pointer
* @count: line number
*
* Return: void
*/
void rotl(stack_t **stack, unsigned int count __attribute__((unused)))
{
	int tmp;
	stack_t *ptr = *stack;

	if (*stack == NULL)
		return;
	tmp = (*stack)->n;
	while (ptr->next != NULL)
	{
		ptr->n = ptr->next->n;
		ptr = ptr->next;
	}
	ptr->n = tmp;
}



/**
* rotr - rotates the last element of a stack_t stack to the top
* @stack: stack double pointer
* @count: line number of opcode
*
* Return: void
*/
void rotr(stack_t **stack, unsigned int count __attribute__((unused)))
{
	int tmp;
	stack_t *ptr = *stack;

	if (*stack == NULL)
		return;

	while (ptr->next != NULL)
		ptr = ptr->next;
	tmp = ptr->n;
	while (ptr->prev != NULL)
	{
		ptr->n = ptr->prev->n;
		ptr = ptr->prev;
	}
	ptr->n = tmp;
}
