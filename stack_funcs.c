#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push - push new node
 * @head: working stack node
 * @line: unsigned value
 * return: void
 */
void push(stack_t **new, __attribute__((unused)) unsigned int line)
{
	printf("Pushing value: %i\n", (*new)->n);

	if (stack_h)
	{
		/* new next point to head  (new -> head) */
		(*new)->next = (stack_h);

		/* head prev points to new (new <- head) */
		(stack_h)->prev = (*new);
	}
	(stack_h) = (*new);
}

/**
 * pop - delete stack
 * @head: working stack
 * @line: uint value
 *
 * return: void
 */

void pop(stack_t **head, __attribute__((unused)) unsigned int line) {}

/**
 * is_stack_empty - checks if stack empty
 * @head:the head of the node
 * @line: non-negative value
 * Return: 1 or 0
 */

unsigned int is_stack_empty(stack_t **head,
			    __attribute__((unused)) unsigned int line)
{
	return 0;
}

/**
 * show_stack - prints out stack
 * @head:stack head
 * @line:non-negative value
 *
 * return: void
 */

void show_stack(stack_t **head, unsigned int line)
{

	stack_t *h = *head;

	if (!h)
		return;

	while (h)
	{
		printf("->%i", h->n);
		h = h->next;
	}
	printf("\n");
}

/**
 * free_stack - free stack
 * @head: head of a stack
 * return: void
 */
void free_stack()
{
	stack_t *tmp;

	while (stack_h)
	{
		tmp = stack_h;
		stack_h = stack_h->next;
		free(tmp);
	}
}
