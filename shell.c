#include "main.h"

/**
 * main - head of the program
 * Return: always succes
 */

int main(void)
{
	char *comand[1024], *line = NULL, *full_path = NULL, *token;
	size_t buffer_size = 0;
	int i;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf(" $ ");
		fflush(stdin);
		signal(SIGINT, interruptHandler);
		if (getline(&line, &buffer_size, stdin) != EOF)
		{
			trim(line);
			if (*line == '\n' || *line == '\t')
				continue;
			token = strtok(line, " \t\n");
			for (i = 0; i < 1024 && token != NULL; i++)
			{
				comand[i] = token;
				token = strtok(NULL, " \t\n");
			}
			comand[i] = NULL;
			if (comand[0] == NULL)
				continue;
			full_path = pathfinder(comand[0]);
			execComand(full_path, comand);
			line = NULL;
			free(full_path);
		}
		else
		{
			free(line);
			return (0);
		}
	}
	free(line);
	for (i = 0; comand[i] != NULL; i++)
		free(comand[i]);
	free(full_path);
	return (0);
}
