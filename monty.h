#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< HEAD
=======
#define uint unsigned int

>>>>>>> e5221fee5d21afab3b1aa506b74ced0ea8287a09
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
<<<<<<< HEAD
        int n;
        struct stack_s *prev;
        struct stack_s *next;
=======
	int n;
	struct stack_s *prev;
	struct stack_s *next;
>>>>>>> e5221fee5d21afab3b1aa506b74ced0ea8287a09
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
<<<<<<< HEAD
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
=======
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
void push(stack_t **head, uint);
void pop(stack_t **head, uint);
void show_stack(stack_t **head, uint);
uint is_stack_empty(stack_t **head, uint);
void show_top(stack_t **head, uint);
void free_stack(stack_t **head);

/* QUEUE FUNCS */
void enqueue(stack_t **head, uint);
void dequeue(stack_t **head, uint);

/* ERRORS */
void malloc_err();
void usage_err();
void open_err(char *filename);
void invalid_op_err(uint line_num, char *opcode);

>>>>>>> e5221fee5d21afab3b1aa506b74ced0ea8287a09
#endif
