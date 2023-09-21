#include "monty.h"
#include <stdlib.h>

/**
 * push - push new node
 * @stack_h: working stack node
 * @line: unsigned value
 * return: void
 */
void push(stack_t **stack_h, int digit,
	  __attribute__((unused)) unsigned int line)
{

	stack_t *tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		free(tmp);
		malloc_err();
	}

	tmp->n = digit;
	tmp->next = *stack_h;
	tmp->prev = NULL;
	*stack_h = tmp;
}

/**
 * pop - delete stack
 * @stack_h: working stack
 * @line: uint value
 *
 * return: void
 */

void pop(stack_t **stack_h, __attribute__((unused)) unsigned int line)
{
	stack_t *ptr = *stack_h;

	if (!is_stack_empty(&ptr, line))
		return;

	while (ptr->next)
		ptr = ptr->next;
	ptr->prev->next = NULL;
}

/**
 * is_stack_empty - checks if stack empty
 * @stack_h:the head of the node
 * @line: non-negative value
 * Return: 1 or 0
 */

unsigned int is_stack_empty(stack_t **stack_h,
			    __attribute__((unused)) unsigned int line)
{
	if (!*stack_h)
		return (0);
	return (1);
}

/**
 * show_stack - prints out stack
 * @stack_h:stack head
 * @line:non-negative value
 *
 * return: void
 */

void show_stack(stack_t **stack_h, __attribute__((unused)) unsigned int line)
{
	stack_t *tmp = *stack_h;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * free_stack - free stack
 * @stack_h: head of a stack
 * return: void
 */

void free_stack(stack_t **stack_h)
{
	stack_t *list;

	while (stack_h)
	{
		list = *stack_h;
		*stack_h = (*stack_h)->next;
		free(list);
	}
}
