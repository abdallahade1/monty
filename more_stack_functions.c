#include "monty.h"

/**
 * add_stack - adds top of stack and second top of stack
 *
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */

void add_stack(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit_error(stack);
	}
	(*stack)->next->n += (*stack)->n;
	pop_stack(stack, line_number);
}

/**
 * nop_stack - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void nop_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
