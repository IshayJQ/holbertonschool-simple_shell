#include "main.h"

int main(void)
{
	char **comand, *token, *line = NULL, *full_path = NULL, *lineptr_copy;
	pid_t child_pid;
	size_t i, buffer_size;
	int status = 0, num_tokens;

	while (1)
	{
		num_tokens = 0;
		if (isatty(STDIN_FILENO))
			printf(" $ ");
		fflush(stdin);
		signal(SIGINT, interruptHandler);
		if (getline(&line, &buffer_size, stdin) == EOF)
		{
			if (*line == '\n' || *line == '\t')
            			continue;
			lineptr_copy = _malloc(strlen(lineptr));
			strcpy(lineptr_copy, lineptr);
			token = strtok(lineptr_copy, " \t\n");
			while (token != NULL)
			{
				num_tokens++;
				token = strtok(NULL, " \t\n");
			}
			comand = _malloc(num_tokens);
			strcpy(lineptr_copy, lineptr);
			token = strtok(lineptr_copy, " \t\n");
			for (i = 0; token != NULL; i++)
			{
				comand[i] = _malloc(strlen(token)), strcpy(comand[i], token);
				token = strtok(NULL, " \t\n");
			}
			comand[i] = NULL;
			full_path = pathfinder(comand[0]);
			exectComand(full_path);
		}
	}
}
