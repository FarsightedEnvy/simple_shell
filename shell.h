#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

int kl_print(char c);
void prompt(void);
ssize_t read_command(char **comm, size_t *k);
char **_strtok(char *comm, char *delim);
void exit_shell(char **tokens, char *comm);
void current_env(void);
void exec_comm(char **args);
int _execve(char **tokens);
int _strcmp(const char *s1, const char *s2);
int find_path(char *command);
int if_path(char *command);
char *build_path(char *command);
char *_getenv(const char *env_var);
char *_strdup(const char *str);
void *_realloc(void *ptr, unsigned int old_ms, unsigned int new_ms);
char *_memcpy(char *dest, char *src, size_t n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen_rec(const char *s);

#endif

