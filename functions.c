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
 * Return: the path comand
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
		while(path_token != NULL)
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
 * exectComand - exect the comand
 * return - not return
 */

void exectComand(char *full_path, char *comand)
{
	pid_t child_pid;
	int status = 0;

	if (builtin(comand) == 0)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(full_path, &comand, environ))
			perror("execve");
		}
		if (child_pid > 0)
			wait(&status);
	}
	exit(status);
}

/**
 * display_environment_var - display environment
 * return - not return
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