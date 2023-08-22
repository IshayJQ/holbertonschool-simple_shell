#include "main.h"

/**
 * main -  print the int of each list
 * Return: always succes
 */

int main(void)
{
	char *lineptr = NULL, *lineptr_copy = NULL, *token = NULL, **av;
	int num_tokens, i;
	size_t n = 0;

	while (1)
	{
		num_tokens = 0;
		printf("Shell $: ");
		if (getline(&lineptr, &n, stdin) != EOF)
		{
			lineptr_copy = malloc(sizeof(char) * strlen(lineptr));
			if (lineptr_copy == NULL)
			{
				perror("Memory allocation error");
				return (0);
			}
			strcpy(lineptr_copy, lineptr);
			token = strtok(lineptr_copy, " \n");
			while (token != NULL)
			{
				num_tokens++;
				token = strtok(NULL, " \n");
			}
			av = malloc(sizeof(char *) * num_tokens);
			if (av == NULL)
			{
				 perror("tsh: memory allocation error");
				 return (0);
			}
			strcpy(lineptr_copy, lineptr);
			token = strtok(lineptr_copy, " \n");
			for (i = 0; token != NULL; i++)
			{
				av[i] = malloc(sizeof(char) * strlen(token));
				strcpy(av[i], token);
				token = strtok(NULL, " \n");
			}
			av[i] = NULL;
			execmd(av);
			
		}
		else
		{
			printf("Exit shell....\n");
			free(lineptr);
			free(av);
			free(lineptr_copy);
			return (0);
		}
	}
	return (0);
}
