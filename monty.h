#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

extern stack_t *hd;
typedef void (*opFunc)(stack_t **, unsigned int);

/* FILES Functions*/
void opn_fl(char *fl_nam);
void rd_fil(FILE *fl_des);
int line_parsing(char *buff, int line_num, int formt);
void fnd_fun(char *opcd, char *val, int line_num, int formt);
void fun_calling(opFunc function, char *opcd,
		char *val, int line_num, int formt);
void push_to_stack(stack_t **stack, unsigned int line_number);
void pall_stack(stack_t **stack, unsigned int line_number);
void pint_stack(stack_t **stack, unsigned int line_number);
void pop_stack(stack_t **stack, unsigned int line_number);
void swap_stack(stack_t **stack, unsigned int line_number);
void add_stack(stack_t **stack, unsigned int line_number);
void nop_stack(stack_t **stack, unsigned int line_number);
int main(int argc, char **argv);
void free_stack(stack_t *head);
/* Nodes Functions */
void freeing_nodes(void);
stack_t *creating_nd(int n);

/*Error exit functions */
void exit_error(stack_t **stack);

#endif
