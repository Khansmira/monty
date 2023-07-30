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


typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
* struct help - argument for the current opcode
* @data_struct: stack and queue
* @arg: arguments
*
* Description: global data structure 
*/
typedef struct help
{
	int data_struct;
	char *args;
} help;
help global;



stack_t *stack_node(stack_t **stack, const int n);
stack_t *queue_node(stack_t **stack, const int n);
void free_stack(stack_t *stack);
size_t print_stack(const stack_t *stack);



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


void opcode(stack_t **stack, char *str, unsigned int count, char *opcode);



int int_digit(char *str);
int is_num(char *str);
int the_comment(char *str, int count);
int _strcmp(char *s1, char *s2);
#endif
