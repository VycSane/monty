#include "monty.h"

/**
 * pchar - prints the char of at the top of the stack
 * @stack: the stack
 * @line_number: Current executing line
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!((*stack)->n >= 0 && (*stack)->n <= 127))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)((*stack)->n));
}

/**
 * pstr - prints the values of the stack as string
 * @stack: the stack
 * @line_number: the executing line of code
 */
void pstr(stack_t **stack, __attribute((unused)) unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	while (tmp != NULL)
	{
		if (!(tmp->n >= 0 && tmp->n <= 127) || tmp->n == 0)
			break;
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
