#include "main.h"

int main(void)
{
	char **comand, *token, *line = NULL, *full_path = NULL, *line_copy;
	size_t i, buffer_size = 0;
	int num_tokens;

	while (1)
	{
		num_tokens = 0;
		if (isatty(STDIN_FILENO))
			printf(" $ ");
		fflush(stdin);
		signal(SIGINT, interruptHandler);
		if (getline(&line, &buffer_size, stdin) != EOF)
		{
			printf ("INGRESE");
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
			strcpy(line_copy, line);
			token = strtok(line_copy, " \t\n");
			for (i = 0; token != NULL; i++)
			{
				comand[i] = _malloc(strlen(token)), strcpy(comand[i], token);
				token = strtok(NULL, " \t\n");
				printf ("[%s]", comand[i]);
			}
			comand[i] = NULL;
			full_path = pathfinder(comand[0]);
			printf ("Path: %s", full_path);
			exectComand(full_path, comand[0]);
			line = NULL, token = NULL, comand[0] = NULL;
		}
		else
		{
			printf("Exit shell...\n"), free(line), free(comand), free(line_copy);
			return (0);
		}
	}
}
