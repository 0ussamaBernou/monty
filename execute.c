#include "monty.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void run_instuction(char *opcode, char *value, uint line_num)
{
	uint i;

	instruction_t instructions[] = {
	    {"push", push}, {"pall", show_stack}, {"pint", pint}, {"pop", pop},
	    {"nop", nop},   {"swap", swap_nodes}, {"add", add},	  {NULL, NULL}};

	if (opcode)
	{

		if (opcode[0] == '#')
			return;

		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(instructions[i].opcode, opcode) == 0)
			{
				exec(instructions[i].f, opcode, value,
				     line_num);
				return;
			}
		}
	}
	else
	{
		return;
	}

	invalid_op_err(line_num, opcode);
}
void exec(void (*func)(stack_t **, uint), char *op, char *value, uint line_num)
{
	int digit, i;

	stack_t *tmp;

	if (strcmp("push", op) == 0)
	{
		if (value == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			free_stack();
			exit(EXIT_FAILURE);
		}

		if ((isdigit(value[0]) == 0) && value[0] != '-' &&
		    value[0] != '\0')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			free_stack();
			exit(EXIT_FAILURE);
		}
		for (i = 1; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n",
					line_num);
				free_stack();
				exit(EXIT_FAILURE);
			}
		}

		digit = atoi(value);

		tmp = malloc(sizeof(stack_t));
		if (!tmp)
		{
			free(tmp);
			malloc_err();
		}

		tmp->prev = NULL;
		tmp->next = NULL;
		tmp->n = digit;
		push(&tmp, line_num);
	}
	else
	{
		func(&stack_h, line_num);
	}
	return;
}
