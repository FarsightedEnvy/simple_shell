#include "shell.h"

/** function that creates path to a regular command */

/**
  * build_path – function that builds a path to regular command
  * @command: pointer to command input from user
  *
  * Return: 1 on success, -1 on failure
*/
char *build_path(char *command)
{
	char *p_env, *p_copy, *command_path;
	char **direct;
	struct stat info;
	
	path_env = _getenv("PATH");
	
	if (p_env == NULL)
		return (NULL);
	p_copy = _strdup(p_env);
	
	if (p_copy == NULL)
		return (NULL);
	direct = _strtok(p_copy, ":");
	
	if (direct == NULL)
	{
		free(p_copy);
		return (NULL);
	}
	for (int i = 0; direct[i]; i++)
	{
		command_path = malloc(_strlen_recursion(direct[i]) + _strlen_recursion(command) + 2);
		
		if (command_path == NULL)
			break;
		_strcpy(command_path, direct[i]);
		_strcat(command_path, "/");
		_strcat(command_path, command);
		path_exist = stat(command_path, &info);
		
		if (path_exist == 0)
		{
			free(p_copy);
			free(direct);
			return (command_path);
		}
		free(command_path);
	}
	free(p_copy);
	free(direct);
	return (NULL);
}

