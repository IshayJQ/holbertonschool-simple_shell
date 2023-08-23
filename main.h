#ifndef _MAIN_H
#define _MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

char **environ;

char compare_strings(char *string1, char *string2, int max_length)
int display_environment_var(void);
char *pathfinder(char *command);
void *_malloc(unsigned int size);
void interruptHandler(int signal);
int builtin(char *user_input);
void exectComand(char *full_path, char *comand);

#endif
