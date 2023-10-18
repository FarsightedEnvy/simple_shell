#include "shell.h"

/**
  * exec_comm - function that executes a command
  * @args : pointer to tokens array
  * Return : Nothing
  */
void exec_comm(char **args)
{
	char *command = NULL;
	int path = if_path(command);

	if (args == NULL || args[0] == NULL)
	{
		perror("./hsh");
		return;
	}

	command = args[0];
	if (_strcmp(command, "env") == 0)
	{
		current_env();
		return;
	}

	if (path == 0)
	{
		if (if_path(command) == 0 && find_path(command) == 0)
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
