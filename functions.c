#include "main.h"

/**
 * _malloc - allocates memory for an array, using malloc.
 * @size: Size of each element
 * Return: pointer to the allocated memory, or 0 in fail
 */

void *_malloc(unsigned int size)
{
	char *memorySpace;

	memorySpace = malloc(sizeof(char) * size);
	if (memorySpace == NULL)
	{
		perror("Memory allocation error");
		return (0);
	}
	return (memorySpace);
}

/**
 * pathfinder - get the path of the comand
 * @command: firts command
 * Return: the path command
 */

char *pathfinder(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		path_copy = strdup(path);
		command_length = strlen(command);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(command, &buffer) == 0)
			return (command);
		return (NULL);
	}
	return (NULL);
}

/**
 * execComand - exec the comand
 * @full_path: path of the command
 * @comand: firts position of the array of strings
 * Return: not return
 */

void execComand(char *full_path, char *comand)
{
	pid_t child_pid;
	int status = 0;

	if (builtin(comand) == 0)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(full_path, &comand, environ))
				perror("execve"), exit(EXIT_FAILURE);
		}
		if (child_pid > 0)
			wait(&status);
	}
}

/**
 * display_environment_var - display environment
 * Return: this return 1 always succes
 */

int display_environment_var(void)
{
	char **envvar = environ;
	int i = 0;

	while (envvar[i])
	{
		write(1, envvar[i], strlen(envvar[i]));
		write(1, "\n", 1);
		++i;
	}
	return (1);
}

/**
 * getCommandArray - get the array of strings
 * @line: pointer to character input user
 * Return: the array of strings
 */

char **getCommandArray(char *line)
{
	char **command, *line_copy, *token;
	int num_tokens = 0, i;

	line_copy = _malloc(strlen(line));
	strcpy(line_copy, line);
	token = strtok(line_copy, " \t\n");
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, " \t\n");
	}
	command = _malloc(num_tokens);
	strcpy(line_copy, line);
	token = strtok(line_copy, " \t\n");
	for (i = 0; token != NULL; i++)
	{
		command[i] = _malloc(strlen(token));
		strcpy(command[i], token);
		token = strtok(NULL, " \t\n");
		printf("[%s]", command[i]);
	}
	command[i] = NULL;
	free(line_copy);
	return (command);
}
