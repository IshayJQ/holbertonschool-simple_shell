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
			printf("---Ingrese--- \n");
			if (*line == '\n' || *line == '\t')
				continue;
			comand = getCommandArray(line);
			full_path = pathfinder(comand[0]);
			printf("Path: %s", full_path);
			execComand(full_path, comand[0]);
			line = NULL;
			comand = NULL;
		}
		else
		{
			printf("Exit shell...\n"), free(line), free(comand);
			return (0);
		}
	}
	return (0);
}
