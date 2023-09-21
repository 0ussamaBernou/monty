#include "monty.h"

/**
 * free_All - this free All memories in stack
 * @stack: this is the working stack node
 * @file: this is the working file
 * return: void
 */

void free_All(stack_t *stack, FILE *file)
{
	static FILE *f;

	if (file)
	{
		f = file;
		return;
	}
	fclose(f);
	free(ln);
	free_List(list);
}

/**
 * filter - this is server a trigger function
 * @stack: this is a working node
 * @line_number: this is non-negative number
 * return: void
 */

void filter(stack_t *stack, unsigned int line_number)
{
	char *tok = strtok(line," ");
	instruction_t inputs[] = { {"push", push}, {"pall", pall}, {"pint", pint},{"pop", pop}, {"add", add}, {"swap", swap}, {"nop", nop},{"sub", sub}, {"div", _div}, {"mul", _mul}, {"mod", _mod},{"pchar", pchar}, {"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr} };
	if (*tok == '\n' || *tok == "#") return;

	size_t pos = 0;

	while (pos < 15)
	{
		if(!strncmp(input[pos].opcode, tok, strlen(tok) - 1))
		{
			input[pos].f(stack, line_number);
			return;
		}
		pos += 1;
	}

	fprintf(stderr, "L%d: unknown instruction %s", line_number, tok);
	free_All(*stack);
	exit(EXIT_FAILURE);
}
