#include "monty.h"

/**
 * show_top - print the top of the stack
 * @stack_h: head of the stack
 * @line: non-negative value
 *
 * return: void
 */

void show_top(stack_t *stack_h, unsigned int line)
{
	printf("%d\n", stack_h->n);
}
