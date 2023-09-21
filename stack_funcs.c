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
 * @head: working stack node
 * line: unsigned value
 * return: void
 */

void push(stack_t **head, unsigned int line)
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
	tmp->next = *head;
	tmp->prev = NULL;
	*head = tmp;
}
