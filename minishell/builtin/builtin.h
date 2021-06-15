#ifndef BUILTIN_H
#define BUILTIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>


int echo(char **option, char *value);
//int pwd(char **option, char *value);
int cd(char **option, char *value);
int pwd();
//int cd();
#endif
