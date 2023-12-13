#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define SUCCESS 0
#define FAIL 1
#define MAXARG 100


void writer(const char *message);
void prompt(void);
void run(const char *cmd);
void reader(char *cmd, size_t s);
void printer(const char *message);
void token(const char *cmd, char *args[]);
void exec(char *args[]);


#endif
