#include "monty.h"

/**
 * check_arg_count - checks the validity of the commandline argument count
 * @argc: commandline arguments count
 * @test_value: value to test against
 * @msg: error message
 */
void check_arg_count(int argc, int test_value, char *msg)
{
	if (argc != test_value)
	{
		write(STDERR_FILENO, msg, strlen(msg));
		exit(EXIT_FAILURE);
	}
}
/**
 * open_file - opens a file with error checking
 * @filepath: location of the file
 * @mode: the access mode
 * Return: a pointer to the file
 */
FILE *open_file(char *filepath, char *mode)
{
	FILE *stream = NULL;

	stream = fopen(filepath, mode);
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filepath);
		exit(EXIT_FAILURE);
	}
	return (stream);
}

/**
 * push - adds node to the start of the list
 * @head: starting node
 * @n: the value to add to the list
 */
void push(stack_t **head, const int n)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t *));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
}
/**
 * pall - prints the values of the stack
 * @stack: the stack
 * @line_number: the executing line of code
 */
void pall(stack_t **stack, __attribute((unused)) unsigned int line_number)
{
	stack_t *tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
