#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>

/** function to exit the shell */

/**
  *exit_shell - function that terminates the shell
  *@tokens : pointer to a null terminated array of strings
  *@comm : buffer storing user command string
  *
  *Return : shell termination
  */
void exit_shell(char **tokens, char *comm)
{
	if (_strcmp(tokens[0], "exit") == 0)
	{
		free(tokens);
		free(comm);
		exit(EXIT_SUCCESS);
	}
}

/** function to print the current environment */

/**
  * current_env - function that prints current environment
  */
void current_env(void)
{
	int l = 0, k = 0;

	while (environ[l] != NULL)
	{
		k = 0;

		while (environ[l][k] != '\0')
		{
			kl_print(environ[l][k]);
			k++;
		}
		kl_print('\n');
		l++;
	}
}

/** function to execute user command */

/**
 *_execve - function that executes a command
 *@tokens: pointer to a null terminated array of strings
 *
 *Return: command output that mimics Linux Bash
 */
int _execve(char **tokens)
{
	pid_t child_pid;
	int status;

	if (tokens == NULL || tokens[0] == NULL)
	{
		perror("./hsh");
		return (-1);
	}
	child_pid = fork();

	if (child_pid == -1)
	{
		perror("./hsh");
		return (-1);
	}
	else if (child_pid == 0)
	{
		if (execve(tokens[0], tokens, environ) == -1)
		{
			perror("./hsh");
			return (-1);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}

/** function that compares 2 strings */

/**
 * _strcmp - function that compares 2 strings
 * @s1: pointer to fist compared string
 * @s2: pointer to second compared string
 *
 * Return: the difference between s1 and s2 ASCII values
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const char *)s1 - *(const char *)s2);

}
