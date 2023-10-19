#include "monty.h"

/**
 * free_stack - free a list
 * @head: pointer to first node
 *
 */
void free_stack(stack_t *head)
{
        stack_t *tmp;

        while (head != NULL)
        {
                tmp = head->next;
                free(head);
                head = tmp;
        }
}
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
