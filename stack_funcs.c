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
	stack_t *tmp;

	if (stack_h)
	{
		tmp = stack_h;
		stack_h = *new;
		stack_h->next = tmp;
		tmp->prev = stack_h;

		printf("pushing %d ...\n", stack_h->n);
	}

	else
	{
		stack_h = *new;

		printf("pushing %d ...\n", (stack_h)->n);
		return;
	}
}

/**
 * pop - delete stack
 * @head: working stack
 * @line: uint value
 *
 * return: void
 */

void pop(stack_t **head, __attribute__((unused)) unsigned int line)
{
	stack_t *ptr = *head;

	if (!is_stack_empty(head, line))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		free_stack();
		exit(EXIT_FAILURE);
	}

	while (ptr->next)
		ptr = ptr->next;
	ptr->prev->next = NULL;
}

/**
 * is_stack_empty - checks if stack empty
 * @head:the head of the node
 * @line: non-negative value
 * Return: 1 or 0
 */

unsigned int is_stack_empty(stack_t **head,
			    __attribute__((unused)) unsigned int line)
{
	if (!*head)
		return (0);

	return (1);
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
	stack_t *tmp;

	if (!is_stack_empty(head, line))
	{
		free_stack();
		fprintf(stderr, "L%d: can't pint, stack empty", line);
		exit(EXIT_FAILURE);
	}

	tmp = *head;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * free_stack - free stack
 * @head: head of a stack
 * return: void
 */
void free_stack()
{
	stack_t *list;

	if (!stack_h)
		return;

	while (stack_h)
	{
		list = stack_h;
		stack_h = stack_h->next;
		free(list);
	}
}
