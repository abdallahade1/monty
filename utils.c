#include "monty.h"

/**
 * creating_nd - create new node
 * @n: added number
 * Return: ptr to node or NULL
 */
stack_t *creating_nd(int n)
{
	stack_t *nd = malloc(sizeof(stack_t));

	if (!nd)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack();
		exit(EXIT_FAILURE);
	}
	nd->next = NULL;
	nd->prev = NULL;
	nd->n = n;
	return (nd);
}

/**
 * free_stack - free a list
 * @head: pointer to first node
 *
 */
void free_stack(void)
{
        stack_t *tmp;

        while (hd != NULL)
        {
                tmp = hd;
		hd = hd->next;
                free(tmp);
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
		free_stack();
	exit(EXIT_FAILURE);
}
