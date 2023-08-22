#include "main.h"

/**
 * main -  print the int of each list
 * @ac: pointer to struct dlistint_t const
 * @av: pointer to string
 * Return: always succes
 */

int main(int ac, char **av)
{
	char *prompt = "(Eshell) $ ";
	char *lineptr = NULL, *lineptr_copy = NULL, *token = NULL;
	int num_tokens = 0, i;
	size_t n = 0;
	ssize_t nchars_read = 0;
	const char *delim = " \n";

	/* declaring void variables */
	(void)ac;
	/* Create a loop for the shell's prompt */
	while (1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);
		/* check if the getline function failed or reached EOF or user use CTRL + D */
		if (nchars_read != EOF)
		{
			/* allocate space for a copy of the lineptr*/
			lineptr_copy = malloc(sizeof(char) * nchars_read);
			if (lineptr_copy == NULL)
			{
				perror("tsh: memory allocation error");
				return (0);
			}
			/* copy lineptr to lineptr_copy */
			strcpy(lineptr_copy, lineptr);
			/********** split the string (lineptr) into an array of words ********/
			/* calculate the total number of tokens */
			token = strtok(lineptr_copy, delim);
			while (token != NULL)
			{
				num_tokens++;
				token = strtok(NULL, delim);
			}
			printf("Numero de tokens: %d \n", num_tokens);
			/* Allocate space to hold the array of strings */
			av = malloc(sizeof(char *) * num_tokens);
			if (av == NULL)
			{
				 perror("tsh: memory allocation error");
				 return (0);
			}
			/* Store each token in the argv array */
			strcpy(lineptr_copy, lineptr);
			token = strtok(lineptr_copy, delim);
			for (i = 0; token != NULL; i++)
			{
				av[i] = malloc(sizeof(char) * strlen(token));
				strcpy(av[i], token);
				printf(">>>>> %s \n", av[i]);
				token = strtok(NULL, delim);
			}
			av[i] = NULL;
			/*to chec the store tokens in av*/
			for (i = 0; i < num_tokens-1; i++)
				printf("%s\n", av[i]);
			execmd(av);
			
		}
		else
		{
			printf("Exit shell....\n");
			/* free up allocated memory */
			free(lineptr);
			free(av);
			free(lineptr_copy);
			return (0);
		}
	}
	return (0);
}
