#include "monty.h"
#include <stdlib.h>

/**
 * push - push new node
 * @head: working stack node
 * @line: unsigned value
 * return: void
 */
void push(stack_t **tmp, __attribute__((unused)) unsigned int line)
{

	if (stack_h)
		(*tmp)->next = stack_h;

	else
		(*tmp)->next = NULL;

	(*tmp)->prev = NULL;
	stack_h = *tmp;
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

	if (!is_stack_empty(&ptr, line))
		return;

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

void show_stack(stack_t **head, __attribute__((unused)) unsigned int line)
{
	stack_t *tmp = *head;

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

void free_stack(stack_t **head)
{
	stack_t *list;

	while (head)
	{
		list = *head;
		*head = (*head)->next;
		free(list);
	}
}
