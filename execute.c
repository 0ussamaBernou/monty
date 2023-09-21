#include "monty.h"
#include <string.h>

void run_instuction(char *opcode, char *value, uint line_num)
{
	uint i;

	instruction_t instructions[] = {
	    {"push", push},	{"pall", show_stack}, {"pint", show_top},
	    {"pop", pop},	{"nop", nop},	      {"swap", swap_nodes},
	    {"add", add_nodes}, {NULL, NULL}};

	if (opcode[0] == '#')
		return;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			exec(instructions[i].f, opcode, value, line_num);
			return;
		}
	}

	invalid_op_err(line_num, opcode);
}
void exec(void (*func)(stack_t **, uint), char *op, char *value, uint line_num)
{
	int digit;

	if (strcmp(op, "push") == 0)
	{

		if (!isdigit(value))
		{
			fprintf(stderr, "L%d: usage: push integer", line_num);
			exit(EXIT_FAILURE);
		}

		digit = atoi(value);
		push(&stack_h, digit, line_num);
	}
	func(&stack_h, line_num);
	return;
}
