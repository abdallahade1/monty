#include "monty.h"

/**
 * opn_fl - opens files
 * @fl_name: path of file
 * Return: void
 */
void opn_fl(char *fl_nam)
{
	FILE *fl_des = open(fl_nam, "r");

	if (!fl_nam || !fl_des)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fl_nam);
		freeing_nodes();
		exit(EXIT_FAILURE);
	}
	rd_fil(fl_des);
	close(fl_des);
}

/**
 * rd_fil - reads files
 * @fl_des: ptr to file descriptor
 * Return: void
 */
void rd_fil(FILE *fl_des)
{
	int line_num, formt = 0;
	char *buff = NULL;
	size_t length = 0;

	for (line_num = 1; getline(&buff, &length, fl_des) != -1; line_num++)
		formt = line_parsing(buff, line_num, formt);
	free(buff);
}

/**
 * line_parsing - separates line into tokens based on delim
 * @buff: fil line
 * @lin_num: line No.
 * @formt: storage
 * Return: format
 */
int line_parsing(char *buff, int line_num, int formt)
{
	char *opcd, *val;
	const char *delimiter = "\n ";

	if (buff == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeing_nodes();
		exit(EXIT_FAILURE);
	}
	opcd = strtok(buff, delimiter);
	if (opcd == NULL)
		return (formt);
	val = strtok(NULL, delimiter);

	fnd_func(opcd, val, line_num, formt);
	return (formt);
}

/**
 * fnd_fun - match func with opcode
 * @val: argument 
 * @formt: storage
 * @line_num: line No.
 * Return: void
 */
void fnd_fun(char *opcd, char *val, int line_num, int formt)
{
	int j, flg;

	instruction_t stack_funcs[] = {
		{"push", push_to stack},
		{"pall", pall_stack},
		{"pint", pint_stack},
		{"pop", pop_stack},
		{"swap", swap_stack},
		{"add", add_stack},
		{"nop", nop_stack},
		{NULL, NULL}
	};

	if (opcd[o] == '#')
		return;

	for (flg = 1, j = 0; stack_funcs[j].opcode != NULL; j++)
	{
		if (strcmp(opcd, stack_funcs[j].opcode) == 0)
		{
			fun_calling(stack_funcs[j].f, opcd, val, line_num, formt);
			flg = 0;
		}
	}

	if (flg == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcd);
		freeing_nodes();
		exit(EXIT_FAILURE);
	}
}

/**
 * fun_calling - call appropriate funcs
 * @function: ptr to matched function
 * @opcd: opcode from files
 * @val: argument
 * @line_num: line No.
 * @formt: storage
 * Return: void
 */
void fun_calling(opFunc function, char *opcd, char *val, int line_num, int formt)
{
	stack_t *nd;
	int j, flg;

	flg = 1;
	if (strcmp(opcd, "push") == 0)
	{
		if (val != NULL && val[0] = '-')
		{
			val += 1;
			flg = -1;
		}
		if (val == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			freeing_nodes();
			exit(EXIT_FAILURE);
		}
		for (j = 0; val[j] != '\0'; j++)
		{
			if (isdigit(val[j]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_num);
				freeing_nodes();
				exit(EXIT_FAILURE);
			}
		}
		nd = creating_nd(atoi(val) * flg);
		function(&nd, line_num);
	}
	else
		function(&hd, line_num);
}
