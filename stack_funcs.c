#include "monty.h"

/**
 * check_int_msg - error func for checking int
 * @tmp1: a stack node
 *
 * return: void
 */

void check_int_msg(stack_t *tmp1)
{
	fprintf(stderr, "L<line_number>: usage: push integer");
	free(tmp1);
	exit(EXIT_FAILURE);
}

/**
 * push - push new node
 * @stack_h: working stack node
 * line: unsigned value
 * return: void
 */

void push(stack_t *stack_h, unsigned int line)
{
	stack_t *tmp = malloc(sizeof(stack_t));
	unsigned int pos = 0;
	char *tok = strtok(NULL, " ");

	if (!tmp)
		malloc_err();
	
	while ( pos < strlen(tok) || *tok == "\n")
	{
		if (!isdigit(tok[i]))
			check_int_msg(tmp);
		pos += 1;
	}
	tmp->n = atoi(tok);
	tmp->next = stack_h;
	tmp->prev = NULL;
	stack_h = tmp;
}

/**
 * pop - delete stack
 * @stack_h: working stack
 * @line: uint value
 *
 * return: void
 */

void pop(stack_t *stack_h, unsigned int line)
{
	stack_t *ptr = stack_h;
	
	if (!is_stack_empty(ptr, line))
		return;

	while (ptr->next)
		ptr = ptr->next;
	ptr->prev->next = NULL;
}

/**
 * is_stack_empty - checks if stack empty
 * @stack_h:the head of the node
 * line: non-negative value
 * return: 1 or 0
 */

unsigned int is_stack_empty(stack_t *stack_h, unsigned int line)
{
	if(!stack_h)
		return 0;
	return 1;
}

/**
 * show_stack - prints out stack
 * @stack_h - stack head
 * @line - non-negative value
 *
 * return: void
 */

void show_stack(stack_t *stack_h, unsigned int line)
{
	stack_t *tmp = stack_h;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

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
	return;
}

void free_stack(stack_t *stack_h)
{
	stack_t list;

	while (stack_h)
	{
		list = stack_h;
		stack_h = stack_h->next;
		free(list);
	}
}
