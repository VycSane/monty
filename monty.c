#include "monty.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument list
 * Return: 0 on Success, Non zero integer otherwise
 */
int main(int argc, __attribute((unused)) char *argv[])
{
	char *filepath = NULL, line[1024], *status;
	char *delim = " \n	", **tokens;
	FILE *stream = NULL;
	unsigned int line_number = 1, i = 0;
	stack_t *stack = NULL;

	check_arg_count(argc, 2, "USAGE: monty file\n");
	filepath = argv[1];

	stream = open_file(filepath, "r");

	while ((status = fgets(line, 1024, stream)))
	{
		if (is_comment(line) || line[0] == '\n')
			continue;
		tokens = str_av(line, delim);
		parse_and_execute(&stack, tokens, line_number);

		line_number++;
		while (tokens[i] != NULL)
		{
			free(tokens[i]);
			i++;
		}
		free(tokens);
	}
	fclose(stream);
	return (0);
}
