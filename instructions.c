#include "monty.h"

void run_instuction(char *opcode, char *value, uint line_num)
{
	uint i;

	instruction_t instructions[] = {
	    {"push", push},	 {"pall", print_stack}, {"pint", print_top},
	    {"pop", pop},	 {"nop", nop},		{"swap", swap_nodes},
	    {"add", add_nodes},	 {"sub", sub_nodes},	{"div", div_nodes},
	    {"mul", mul_nodes},	 {"mod", mod_nodes},	{"pchar", print_char},
	    {"pstr", print_str}, {"rotl", rotl},	{"rotr", rotr},
	    {NULL, NULL}};

	if (opcode[0] == '#')
		return;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			exec(instructions[i].f, value, line_num);
			return;
		}
	}
	invalid_op_err(line_num, opcode);
}
void exec(void *func, char *value, uint line_num) { return; }
