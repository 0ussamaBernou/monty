#ifndef MONTY_H
#define MONTY_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define uint unsigned int

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *stack_h;

/* File Funcs */
void read_file(char *filename);
void parseline(char *linebuf, uint line_num);
void run_instuction(char *opcode, char *value, uint line_num);
void exec(void *func, char *value, uint line_num);

/* STACK FUNCS */
void push(uint);
void pop(uint);
void show_stack(uint);
uint is_stack_empty(uint);
void show_top(uint);
void free_stack();

/* QUEUE FUNCS */
void enqueue(uint);
void dequeue(uint);

/* ERRORS */
void malloc_err();
void usage_err();
void open_err(char *filename);
void invalid_op_err(uint line_num, char *opcode);

/* INSTRUCTIONS */

#endif
