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
