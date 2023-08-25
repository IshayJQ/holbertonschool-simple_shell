#include "main.h"

/**
 * builtin - Funtion that call the env or the exit
 * @comand: command a verificar
 * Return: return 1 if found exit or env, 0 if not
 */

int builtin(char *comand)
{
	if (strcmp(comand, "exit") == 0)
	{
		free(comand);
		display_environment_var();
		exit(EXIT_SUCCESS);
		return (1);
	}
	else if (strcmp(comand, "env") == 0)
	{
		display_environment_var();
		free(comand);
		return (1);
	} else
		return (0);
}

/**
 * interruptHandler - interruot the process
 * @signal: signal
 * Return: not return
 */

void interruptHandler(int signal)
{
	(void) signal;
	write(STDIN_FILENO, "\n $ ", 4);
}
