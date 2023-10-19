#include "monty.h"
/**
 * exit_error - frees the stack and exits due to erro
 * @stack: pointer to the head of the stack
 *
 */
void exit_error(stack_t **stack)
{
	if (*stack)
		free_stack(*stack);
	exit(EXIT_FAILURE);
}
