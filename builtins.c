#include "main.h"

/**
 * builtin - Funtion that call the env or the exit
 * @comand: command a verificar
 * Return: return 1 if found exit or env, 0 if not
 */

int builtin(char **comand)
{

	if (strcmp(comand[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
		return (1);
	}
	else if (strcmp(comand[0], "env") == 0)
	{
		display_environment_var();
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
