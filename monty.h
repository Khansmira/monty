#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <stddef.h>



/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;



/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



/**
 * struct GlobalStruct - contains all globals
 * @data: int for push
 * @fm: file stream for monty file
 * @lineptr: pointer to char sting allocated by getline function
 */
struct GlobalStruct
{
	int data;
	FILE *fm;
	char *lineptr;
} globes;




void push(stack_t **stack, unsigned int count);
void pall(stack_t **stack, unsigned int count);
void pint(stack_t **stack, unsigned int count);
void pop(stack_t **stack, unsigned int count);
void swap(stack_t **stack, unsigned int count);
void op_add(stack_t **stack, unsigned int count);
void nop(stack_t **stack, unsigned int count);
void op_sub(stack_t **stack, unsigned int count);
void op_div(stack_t **stack, unsigned int count);
void mul(stack_t **stack, unsigned int count);
void mod(stack_t **stack, unsigned int count);
void pchar(stack_t **stack, unsigned int count);
void pstr(stack_t **stack, unsigned int count);
void rotl(stack_t **stack, unsigned int count);
void rotr(stack_t **stack, unsigned int count);


void opc(stack_t **stack, unsigned int line_number, char *opcode);


int _iswhitespace(void);
void exit_free(stack_t *stack);
void free_stack(stack_t *stack);

#endif
