#include "shell.h"
#include <stdlib.h>
#include <stddef.h>

/** function to find PATH */

/**
  * find_path - function that finds a file path
  * @command: pointer to tokens array
  *
  * Return: 1 if path exists, -1 on failure
*/
int find_path(char *command)
{
	struct stat info;
	int path_exist;

	if (command == NULL)
		return (-1);

	path_exist = stat(command, &info);
	if (path_exist == 0)
		return (0);
	else
		return (-1);
}

/** function that checks if path exists */

/**
  * if_path - function that checks if a full path was given
  * @command: pointer to command input from user
  *
  * Return: 1 if path was given, -1 on failure
*/

int if_path(char *command)
{
	while (*command)
	{
		if (*command == '/')
			return (0);
		command++;
	}
	return (-1);
}

/** function that gets an environment variable */

/**
  * _getenv - function that gets an enviroment variable
  * @env_var: pointer to environment variable
  *
  * Return: pointer to environment or NULL for failure
*/

char *_getenv(const char *env_var)
{
	int l = 0, len;
	char *curr_env_copy, *tok;

	len = _strlen_rec(env_var);

	while (environ[l])
	{
		curr_env_copy = _strdup(environ[l]);
		tok = strtok(curr_env_copy, "=");
		if (_strcmp(tok, env_var) == 0)
		{
			free(curr_env_copy);
			return (&(environ[l][len + 1]));
		}
		free(curr_env_copy);
		l++;
	}
	return (NULL);
}

/**
  * resize_buff - function that resizes buffer
  * @comm: pointer to buffer to resize
  * @pre_size: pointer to size of command input buffer
  *
  * Return: pointer to new buffer
 */
char **resize_buff(char **comm, unsigned int pre_size)
{
	unsigned int new_size;

	new_size = pre_size * 2;
	comm = _realloc(comm, pre_size, new_size);
	if (comm == NULL)
	{
		perror("./hsh");
		return (NULL);
	}
	return (comm);
}
