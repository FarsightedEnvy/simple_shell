#include “shell.h”
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
		while (environ[l][k] != '\0')
		{
			kl_print(environ[l][k]);
			k++;
		}
		kl_print('\n');
		l++;
	}
}

/** function to execute command input */

/**
  * exec_comm - function that executes a command
  * @args : pointer to tokens array
  *
  * Return : Nothing
*/

void exec_comm(char **args)
{
	if (args == NULL || args[0] == NULL)
		return (NULL);

	char *command = args[0];

	if (_strcmp(command, "env") == 0)
	{
		printenv();
		return;
	}
	int path = if_path(command);

	if (path == 0)
	{
		int path_exist = find_path(command);

		if (path_exist == 0)
			_execve(args);
		else
			perror("./hsh");
	}
	else
	{
		char *command_path = build_path(command);

		if (command_path != NULL)
		{
			args[0] = command_path;
			_execve(args);
			free(command_path);
		}
		else
		{
			perror("./hsh");
		}
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
	else if (child_pid == 0
	{
	if (execve(tokens[0], tokens, environ) == -1)
	{
		perror("./hsh");
		return (-1);
	}
	}
	else
	{
	waitpid(child_pid, &status, 0);
	return (0);
	}
}

/** function that compares 2 strings */

/**
 * _strcmp - function that compares 2 strings
 * @s1: pointer to fist compared string
 * @s2: pointer to second compared string
 *
 * Return: the difference between s1 and s2 ASCII values
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);

}
