#include "monty.h"

/**
 * push_to_stack - push int to a stack
 * @new_nd: linked lists for monty stack
 * @line_num: number of line opcode occurs on
 */
void push_to_stack(stack_t **new_nd,
		__attribute__ ((unused))unsigned int line_num)
{
	stack_t *temp;

	if (new_nd == NULL || *new_nd == NULL)
		exit(EXIT_FAILURE);
	if (hd == NULL)
	{
		hd = *new_nd;
		return;
	}
	temp = hd;
	hd = *new_nd;
	hd->next = temp;
	temp->prev = hd;
}

/**
 * pall_stack - print all function
 * @stack: pointer to linked list stack
 * @line_num: number of line opcode occurs on
 */
void pall_stack(stack_t **stack,
		__attribute__ ((unused))unsigned int line_num)
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
 * @line_num: number of line opcode occurs on
 *
 */
void pint_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *itr;

	itr = *stack;

	if (stack == NULL || itr == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_num);
		exit_error();
	}
	printf("%d\n", itr->n);
}

/**
 * pop_stack - delete item at top of stack
 * @stack: pointer to linked list stack
 * @line_num: number of line opcode occurs on
 */
void pop_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *itr;


	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_num);
		exit_error();
	}

	itr = *stack;
	*stack = itr->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(itr);
}

/**
 * swap_stack - swap top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line_num: number of line opcode occurs on
 *
 */
void swap_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *itr;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_num);
		exit_error();
	}

	itr = (*stack)->next;
	(*stack)->next = itr->next;
	if (itr->next != NULL)
		itr->next->prev = *stack;
	itr->next = *stack;
	(*stack)->prev = itr;
	itr->prev = NULL;
	*stack = itr;
}
