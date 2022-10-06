#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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

void check_arg_count(int argc, int test_value, char *msg);
FILE *open_file(char *filepath, char *mode);

ssize_t brk_at_delimiter(char *str, char *delimiter);
char **str_av(char *str, char *delimiter);
bool is_comment(char *line);
bool is_integer(char *num_str);
void push(stack_t **head, const int n);
void pall(stack_t **stack, __attribute((unused)) unsigned int line_number);
void parse_and_execute(stack_t **s, char **tokens, size_t line_number);
void search_and_execute(stack_t **s, char *opcode, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(__attribute((unused)) stack_t **stack,
		 __attribute((unused)) unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, __attribute((unused)) unsigned int line_number);
#endif /* MONTY_H */