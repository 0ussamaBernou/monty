#include "monty.h"
#include <stdlib.h>

/**
 * push - push new node
 * @head: working stack node
 * @line: unsigned value
 * return: void
 */
<<<<<<< HEAD
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
=======
void push(stack_t **tmp, __attribute__((unused)) unsigned int line)
{

	if (stack_h)
		(*tmp)->next = stack_h;

	else
		(*tmp)->next = NULL;
>>>>>>> 17c0f9a415e5c66e3a2845273241f15f523aeca6

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

<<<<<<< HEAD
<<<<<<< HEAD
void pop(uint line)
=======
void pop(stack_t **stack_h, __attribute__((unused)) unsigned int line)
>>>>>>> f4aca8110c2f4735b1aebc4645b09f91319c39b8
=======
void pop(stack_t **head, __attribute__((unused)) unsigned int line)
>>>>>>> 17c0f9a415e5c66e3a2845273241f15f523aeca6
{
	stack_t *ptr = *head;

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
 * @head:the head of the node
 * @line: non-negative value
 * Return: 1 or 0
 */
<<<<<<< HEAD
uint  is_stack_empty(unint line)
=======

unsigned int is_stack_empty(stack_t **head,
			    __attribute__((unused)) unsigned int line)
>>>>>>> f4aca8110c2f4735b1aebc4645b09f91319c39b8
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
 * @head: head of a stack
 * return: void
 */

<<<<<<< HEAD
void free_stack(void)
=======
void free_stack(stack_t **head)
>>>>>>> 17c0f9a415e5c66e3a2845273241f15f523aeca6
{
	stack_t *list;

	while (head)
	{
		list = *head;
		*head = (*head)->next;
		free(list);
	}
}
