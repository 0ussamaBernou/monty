#include "monty.h"

/**
 * push - pushes a new node into the stack
 * @stack: this is the stack we working on
 * @line_number: is a non negative number in a monty file
 * return: return nothing
 */

void push( stack_t **stack, unsigned int line_number)
{
	stack_t *new_st = malloc(sizeof(stack_t));
	size_t pos;
	char *tok;

	if(!new_st)
	{
		fprint(stderr, "%s", "Error: malloc failed");
		free_All(*stack, NULL);
		exit(EXIT_FAILURE);
	}
	tok = strtok(NULL, " ");
	pos = 0;

	while (pos < strlen(tok) || *tok == "\n")
	{
		if (!isdigit(tok[i]))
		{
			fprintf(stderr, "L<line_number>: usage: push integer");
			free(new_st);
			free_All(*stack, NULL);
			exit(EXIT_FAILURE);
		}
		pos += 1;
	}
	(*new_st).n = atoi(tok);
	(*new_st).next = *stack;
	new_st->prev = NULL;
	*stack = new_st;
}

/**
 * pall - this function prints all the int in nodes
 * @stack_t: this is the working stack node
 * return: return void
 */

void pall(stack_t **stack)
{
	stack_t h = *stack;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
