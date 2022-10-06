#include "monty.h"

/**
 * pop - pos the top of the stack
 * @stack: the stack
 * @line_number: Current executing line
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * swap - swaps the two topmost values of the stack
 * @stack: the stack
 * @line_number: Current executing line
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *a = *stack;
	stack_t *b = *stack;
	int tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	b = (*stack)->next;
	tmp = a->n;
	a->n = b->n;
	b->n = tmp;
}

/**
 * add - adds the two topmost values of the stack
 * @stack: the stack
 * @line_number: Current executing line
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *a = *stack;
	stack_t *b = *stack;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	b = (*stack)->next;
	b->n = b->n + a->n;
	pop(stack, line_number);
}

/**
 * nop - does nothing
 * @stack: the stack
 * @line_number: Current executing line
 */
void nop(__attribute((unused)) stack_t **stack,
		 __attribute((unused)) unsigned int line_number)
{
}
