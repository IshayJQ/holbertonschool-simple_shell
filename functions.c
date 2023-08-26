#include "main.h"

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

void execComand(char *full_path, char **comand)
{
	pid_t child_pid;
	int status = 0;

	if (builtin(comand) == 0)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(full_path, comand, environ) == -1)
				perror("Command not found "), exit(EXIT_FAILURE);
		}
		if (child_pid > 0)
			wait(&status);
	}
}

/**
 * display_environment_var - display environment
 * Return: not return
 */

void display_environment_var(void)
{
	char **envvar = environ;
	int i = 0;

	while (envvar[i])
	{
		write(1, envvar[i], strlen(envvar[i]));
		write(1, "\n", 1);
		++i;
	}
}

/**
 * trim - verify the posible space in the input
 * @str: line input
 */

void trim(char *str)
{
	int start = 0, end = strlen(str) - 1;
	int i, j;

	/* Buscar el primer índice no espaciado */
	while (str[start] != '\0' && (str[start] == ' ' || str[start] == '\t'))
	{
		start++;
	}
	/* Buscar el último índice no espaciado */
	while (end >= 0 && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n'))
	{
		end--;
	}
	/* Copiar los caracteres no espaciados al principio de la cadena */
	for (i = start, j = 0; i <= end; i++, j++)
	{
		str[j] = str[i];
	}
	/* Agregar el carácter nulo al final*/
	str[j] = '\0';
}
