#include "monty.h"

/**
 * push_to_stack - push int to a stack
 * @stack: linked lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void push_to_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;



	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		printf("Error: malloc failed\n");
		exit_error(stack);
	}

}

/**
 * pall_stack - print all function
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void pall_stack(stack_t **stack,
		__attribute__ ((unused))unsigned int line_number)
{
	stack_t *itr;

	itr = *stack;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	while (itr != NULL)
	{
		printf("%d\n", itr->n);
		itr = itr->next;
	}
}

/**
 * pint_stack - print int a top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void pint_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *itr;

	itr = *stack;

	if (itr != NULL)
	{
		printf("%d\n", itr->n);
	}
	printf("L%d: can't pint, stack empty\n", line_number);
	exit_error(stack);
}

/**
 * pop_stack - delete item at top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void pop_stack(stack_t **stack, unsigned int line_number)
{
	stack_t = *itr;
	itr = *stack;

	if (*stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit_error(stack);
	}
	*stack = itr->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(itr);
}
/**
 * swap_stack - swap top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void swap_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *itr;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit_error(stack);
	}
	itr = *stack;
	int tmp;

	tmp = itr->n;
	itr->n = itr->next->n;
	itr->itr->n = tmp;
}
