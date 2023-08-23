#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

char *pathfinder(char *command);
void *_malloc(unsigned int size);
void interruptHandler(int signal);
int builtin(char *user_input);
