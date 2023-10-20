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
		exit_error();
	}
	nd->next = NULL;
	nd->prev = NULL;
	nd->n = n;
	return (nd);
}

/**
 * free_stack - free a list
 * Return: void
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
 * Return: void
 *
 */
void exit_error(void)
{
	free_stack();
	exit(EXIT_FAILURE);
}
