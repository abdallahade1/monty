#include "monty.h"

/**
 * add_stack - adds top of stack and second top of stack
 *
 * @stack: pointer to linked list stack
 * @line_num: number of line opcode occurs on
 */

void add_stack(stack_t **stack, unsigned int line_num)
{
	int summ;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_num);
		exit_error();
	}
	(*stack) = (*stack)->next;
	summ = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = summ;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * nop_stack - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void nop_stack(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}
