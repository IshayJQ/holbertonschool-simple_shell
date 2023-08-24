#ifndef _MAIN_H
#define _MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

void display_environment_var(void);
char *pathfinder(char *command);
void interruptHandler(int signal);
int builtin(char *user_input);
void execComand(char *full_path, char **comand);

#endif
