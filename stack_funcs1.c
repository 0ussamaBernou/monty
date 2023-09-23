#include "monty.h"
#include <stdio.h>

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

void swap_nodes(stack_t **head, unsigned int line)
{
	stack_t *ptr;

	if (!*head || !(**head).next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		free_stack();
		exit(EXIT_FAILURE);
	}

	ptr = (*head)->next;
	(*head)->next = ptr->next;
	(*head)->prev = ptr;
	ptr->next = *head;
	ptr->prev = NULL;
	(*head) = ptr;
}

/**
 * add - sum both first and second value
 * @stack: head of stack
 * @line: non-negative value
 * return: void
 */
void add(stack_t **head, unsigned int line)
{
	stack_t *ptr;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		free_stack();
		exit(EXIT_FAILURE);
	}
	ptr = (*head)->next;
	(ptr)->n += (*head)->n;
	pop(head, line);
}

/**
 * nop - dont do anything
 * @head: this is head stack node
 * @line: non-negative value
 * return: void
 */
void nop(__attribute__((unused)) stack_t **head,
	 __attribute__((unused)) unsigned int line)
{
	return;
}

/**
 * pint  - print element top of the stack
 * @head: head of the stack
 * @line: line number
 *
 * Return: void
 */
void pint(stack_t **head, uint line)
{

	if (is_stack_empty(head, line) == 0)
	{
		free_stack();
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*head)->n);
	}
}
