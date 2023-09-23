#include "monty.h"
#include <stdio.h>

/**
 * malloc_err - handles failed malloc
 *
 * @head:the stack head
 *
 * Return: void
 */
void malloc_err()
{
	free_stack();
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * usage_err - handles args errors
 *
 * Return: void
 */
void usage_err()
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * open_err - handles file opening error
 *
 * @filename: the file name
 *
 * Return: void
 */
void open_err(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * invalid_op_err - handles invalid op
 *
 * @head: head of the stack
 * @line_num: current line number
 * @opcode: the invalid opcode
 *
 * Return: void
 */
void invalid_op_err(uint line_num, char *opcode)
{

	free_stack();
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
	exit(EXIT_FAILURE);
}
