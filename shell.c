#include "main.h"

/**
 * main - head of the program
 * Return: always succes
 */

int main(void)
{
	char **comand, *line = NULL, *full_path = NULL, *line_copy, *token;
	size_t buffer_size = 0;
	int num_tokens;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf(" $ ");
		fflush(stdin);
		signal(SIGINT, interruptHandler);
		num_tokens = 0;
		if (getline(&line, &buffer_size, stdin) != EOF)
		{
			if (*line == '\n' || *line == '\t')
				continue;
			line_copy = _malloc(strlen(line));
			strcpy(line_copy, line);
			token = strtok(line_copy, " \t\n");
			while (token != NULL)
			{
				num_tokens++;
				token = strtok(NULL, " \t\n");
			}
			comand = _malloc(num_tokens);
			comand = getCommandArray(line, comand);
			full_path = pathfinder(comand[0]);
			printf ("%s \n", comand[0]);
			printf ("%s \n", full_path);
			execComand(full_path, comand);
			line = NULL, comand = NULL;
		}
		else
		{
			free(line), free(comand), free(full_path), free(line_copy);
			return (0);
		}
	}
}
