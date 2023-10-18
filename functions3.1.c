#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>

/** function that creates path to a regular command */

/**
  * build_path - function that builds a path to regular command
  * @command: pointer to command input from user
  *
  * Return: 1 on success, -1 on failure
*/
char *build_path(char *command)
{
	char *p_env = _getenv("PATH"), *p_copy, *comm_path, **dir;
	struct stat info;
	int i, path_exist;

	p_copy = _strdup(p_env);
	dir = _strtok(p_copy, ":");

	for (i = 0; dir[i]; i++)
	{
		comm_path = malloc(sizeof(char) * 4096);

		if (comm_path == NULL)
		{
			free(p_copy);
			free(dir);
			return (NULL);
		}
		_strcpy(comm_path, dir[i]);
		_strcat(comm_path, "/");
		_strcat(comm_path, command);
		path_exist = stat(comm_path, &info);

		if (path_exist == 0)
		{
			free(p_copy);
			free(dir);
			return (comm_path);
		}
		free(comm_path);
	}
	free(p_copy);
	free(dir);
	return (NULL);
}

