#include "monty.h"

/**
 * sub - subtracts the two topmost values of the stack
 * @stack: the stack
 * @line_number: Current executing line
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *a = *stack;
	stack_t *b = *stack;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	b = (*stack)->next;
	b->n = b->n - a->n;
	pop(stack, line_number);
}

/**
 * mul - multiplies the two topmost values of the stack
 * @stack: the stack
 * @line_number: Current executing line
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *a = *stack;
	stack_t *b = *stack;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	b = (*stack)->next;
	b->n = b->n * a->n;
	pop(stack, line_number);
}

/**
 * mod - calculates mod of the two topmost values of the stack
 * @stack: the stack
 * @line_number: Current executing line
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *a = *stack;
	stack_t *b = *stack;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (a->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	b = (*stack)->next;
	b->n = b->n % a->n;
	pop(stack, line_number);
}
