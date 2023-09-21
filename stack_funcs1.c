#include "monty.h"

/**
 * show_top - print the top of the stack
 * @head: head of the stack
 * @line: non-negative value
 *
 * return: void
 */

void show_top(stack_t **head, __attribute__((unused)) unsigned int line)
{
	printf("%d\n", (*head)->n);
}
