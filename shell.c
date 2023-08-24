#include "main.h"

/**
 * main - head of the program
 * Return: always succes
 */

int main(void)
{
	char **comand, *line = NULL, *full_path = NULL;
	size_t buffer_size = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf(" $ ");
		fflush(stdin);
		signal(SIGINT, interruptHandler);
		if (getline(&line, &buffer_size, stdin) != EOF)
		{
			if (*line == '\n' || *line == '\t')
				continue;
			comand = getCommandArray(line);
			full_path = pathfinder(comand[0]);
			execComand(full_path, comand);
			line = NULL;
			comand = NULL;
		}
		else
		{
			free(line), free(comand);
			return (0);
		}
	}
	return (0);
}
