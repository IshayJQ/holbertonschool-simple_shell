#include "main.h"

/**
 * builtin - Funtion that call the env or the exit
 * @command: command a verificar
 * Return: Integer
 */

int builtin(char *comand)
{
	if (strcmp(comand, "exit") == 0)
	{
		free(comand);
		exit(EXIT_SUCCESS);
		return (1);
	} 
	else if (strcmp(comand,"env") == 0)
	{
		display_environment_var();
		free(comand);
		return (1);
	} else
		return (0);
}

void interruptHandler(int signal)
{
	(void) signal;
	write(STDIN_FILENO, "\n $ ", 4);
}
