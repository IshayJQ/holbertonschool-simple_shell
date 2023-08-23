#include "main.h"

/**
 * builtin - Funtion that call the env or the exit
 * @command: command a verificar
 * Return: Integer
 */

int builtin(char *comand)
{
	if (compare_strings(comand, "exit", 4) == 0)
	{
		free(user_input);
		exit(EXIT_SUCCESS);
		return (1);
	} else if (compare_strings(comand,"env", 3) == 0)
	{
		display_environment_var();
		free(user_input);
		return (1);
	} else
		return (0);
}

void interruptHandler(int signal)
{
	(void) signal;
	write(STDIN_FILENO, "\n $ ", 4);
}
