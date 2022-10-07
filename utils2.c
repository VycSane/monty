#include "monty.h"
/**
 * parse_and_execute - parses and executes the bytecodes per line
 * @s: the stack for storing argument values
 * @tokens: array of tokens (list of words that makes up a line)
 * @line_number: Current executing line
 */
void parse_and_execute(stack_t **s, char **tokens, size_t line_number)
{
	char *opcode, *num_str = NULL;

	opcode = tokens[0];

	if (opcode)
	{
		num_str = tokens[1];
		if (strcmp(opcode, "push") == 0)
		{
			if (is_integer(num_str))
			{
				push(s, atoi(num_str));
			}
			else
			{
				fprintf(stderr, "L%ld: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			search_and_execute(s, opcode, line_number);
		}
	}
}

/**
 * search_and_execute - parses and executes the bytecodes per line
 * @s: the stack
 * @opcode: the opcode to lookup
 * @line_number: Current executing line
 */
void search_and_execute(stack_t **s, char *opcode, unsigned int line_number)
{
	size_t i = 0;
	instruction_t commands[11];
	char *name_table[] = {
		"pall", "pint", "pop", "swap", "add", "nop",
		"sub", "mul", "mod", "pchar", "pstr", NULL};
	typedef void (*FunctionCallback)(stack_t(**stack), unsigned int line_number);
	FunctionCallback(functions_table)[] = {
		pall, pint, pop, swap, add, nop, sub, mul, mod, pchar, pstr, NULL};

	while (name_table[i] != NULL)
	{
		commands[i].opcode = name_table[i];
		commands[i].f = functions_table[i];
		i++;
	}
	i = 0;
	while (name_table[i] != NULL)
	{
		if (strcmp(name_table[i], opcode) == 0)
		{
			commands[i].f(s, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 * pint - prints the value on top of the stack
 * @stack: the stack
 * @line_number: Current executing line
 */
void pint(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
