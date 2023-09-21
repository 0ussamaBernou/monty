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

void swap_nodes(stack_t **stack_h, unsigned int line)
{
	if (!*stack_h || !(**stack_h).next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		free_stack();
		exit(EXIT_FAILURE);
	}
	stack_t *ptr = stack_h->next;
	stack_h->next = ptr->next;
	stack_h->prev = ptr;
	ptr->next = *stack_h;
	ptr->prev = NULL;
	(*stack_h) = ptr;
}


/**
 * add - sum both first and second value
 * @stack: head of stack
 * @line: non-negative value
 * return: void
 */

void add(stack_t **stack_h, unsigned int line)
{
	if (*stack_h == NULL || !(**stack_h).next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		free_stack();
		exit(EXIT_FAILURE);
	}
	stack_t **ptr = (**stack_h).next;
	(**ptr).n += (**stack_h).n;
	pop(stack_h, line);
}
/**
 * nop - donot do anything
 * @stack_h: this is head stack node
 * @line: non-negative value
 * return: void
 */

void nop(stack_t **stack_h, unsigned int line)
{
}
