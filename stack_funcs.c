#include "monty.h"
#include <stdlib.h>

/**
 * push - push new node
 * @stack_h: working stack node
 * @line: unsigned value
 * return: void
 */
<<<<<<< HEAD

void push(uint line)
=======
void push(stack_t **stack_h, int digit,
	  __attribute__((unused)) unsigned int line)
>>>>>>> f4aca8110c2f4735b1aebc4645b09f91319c39b8
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

<<<<<<< HEAD
void pop(uint line)
=======
void pop(stack_t **stack_h, __attribute__((unused)) unsigned int line)
>>>>>>> f4aca8110c2f4735b1aebc4645b09f91319c39b8
{
	stack_t *ptr = *stack_h;

	if (!is_stack_empty(line))
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
 * @stack_h:the head of the node
 * @line: non-negative value
 * Return: 1 or 0
 */
<<<<<<< HEAD
uint  is_stack_empty(unint line)
=======

unsigned int is_stack_empty(stack_t **stack_h,
			    __attribute__((unused)) unsigned int line)
>>>>>>> f4aca8110c2f4735b1aebc4645b09f91319c39b8
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

	if (!is_stack_empty(line))
	{
		free_stack();
		fprintf(stderr, "L<line_number>: can't pint, stack empty");
		exit(EXIT_FAILURE);
	}

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

void free_stack(void)
{
	stack_t *list;

	while (stack_h)
	{
		list = *stack_h;
		*stack_h = (*stack_h)->next;
		free(list);
	}
}
