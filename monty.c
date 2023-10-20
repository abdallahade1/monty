#include "monty.h"
stack_t *hd = NULL;

/**
 * main - driver function for monty program
 * @argc: int num of arguments
 * @av: opcode file
 * Return: 0
 */

int main(int argc, char **av)
{
	/*
	 * stack_t *stack;
	 * stack = NULL;
	 */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit_error();
	}
	opn_fl(av[1]);
	free_stack();
	return (0);
}
