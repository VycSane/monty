#include "monty.h"

/**
 * is_comment - checks if a line of the bytecode is a comment
 * @line: the line of code
 * Return: true if it is a comment, false otherwise
 */
bool is_comment(char *line)
{
	size_t i = 0;

	while (line[i] == ' ')
		i++;
	if (line[i] == '#')
		return (true);
	return (false);
}

/**
 * brk_at_delimiter - replaces specified delimiters with null bytes (\0)
 * @str: the string argument (note: string is modified)
 * @delimiter: list (string) of delimiters
 *
 * Return: the number of tokens that makes up the string, -1 0n error
 */
ssize_t brk_at_delimiter(char *str, char *delimiter)
{
	size_t delimeter_length, str_len, i, j, k = 0;
	ssize_t count = 0;

	if (delimiter == NULL || str == NULL)
		return (-1);
	/* Setting number of delimeters passed & the length of string */
	delimeter_length = strlen(delimiter);
	str_len = strlen(str);
	/* Looping through the duplicated string */
	for (i = 0; i < str_len; i++)
	{
		/* Looping through the delimiter list (string) */
		for (j = 0; j < delimeter_length; j++)
		{
			/* Replacing any delimiter found with (char -> \0) */
			if (str[i] == delimiter[j])
				str[i] = '\0';
		}
	}
	/* Counting the total tokens in the duplicated string */
	while (k < str_len)
	{
		if ((str[k] != '\0' && str[k + 1] == '\0'))
			count++;
		k++;
	}
	return (count);
}

/**
 * str_av - generates a null terminated list of tokens from a string
 * @str: the string argument (note: string is modified)
 * @delimiter: list (string) of delimiters
 *
 * Return: array containig tokens
 */
char **str_av(char *str, char *delimiter)
{
	bool start = false;
	char **av = NULL, *temp_str;
	size_t i = 0, start_pos = 0, stop_pos = 0, curr_pos = 0, ptr = 0, str_len;
	ssize_t count = 0;

	str_len = strlen(str);
	count = brk_at_delimiter(str, delimiter);
	av = malloc((count + 1) * sizeof(char *));
	if (av == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	for (curr_pos = 0; curr_pos <= str_len; curr_pos++)
	{
		if (start && str[curr_pos] == '\0')
		{
			stop_pos = curr_pos;
			start = false;
			temp_str = malloc((stop_pos - start_pos + 1) * sizeof(char));
			if (temp_str == NULL)
			{
				fprintf(stderr, "Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}
			while (start_pos < stop_pos)
				temp_str[ptr++] = str[start_pos++];
			temp_str[ptr] = '\0';
			av[i++] = temp_str;
			ptr = 0;
		}
		if (str[curr_pos] != '\0' && !start)
		{
			start_pos = curr_pos;
			start = true;
		}
	}
	av[count] = NULL;
	return (av);
}

/**
 * is_integer - checks if a number is an integer
 * @num_str: the string format of the number to check
 * Return: true if number is integer, false otherwise
 */
bool is_integer(char *num_str)
{
	size_t i = 0, len;
	char digit;

	if (num_str == NULL)
		return (false);
	len = strlen(num_str);
	while (i < len)
	{
		digit = num_str[i];
		if (!((digit >= 48 && digit <= 57) || digit == '+' || digit == '-'))
			return (false);
		i++;
	}
	return (true);
}
