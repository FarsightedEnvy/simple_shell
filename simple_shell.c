#include "shell.h"

/**
  *main- Entry point
  *Return: Always 0 (Success)
  */

int main(void)
{
	int status = 0;
	size_t k = 0;
	char *comm = NULL, *delim = " \n\t\a\r";
	char **tokens;

	if (isatty(STDIN_FILENO) == 1)
		prompt();

	while ((status = read_command(&comm, &k)) != -1)
	{
		tokens = _strtok(comm, delim);
		if (*comm == '\n' || *tokens == NULL)
		{
			free(tokens);
			if (isatty(STDIN_FILENO) == 1)
				prompt();

			continue;
		}
		exit_shell(tokens, buff);
		exec_comm(tokens);
		free(tokens);
		if (isatty(STDIN_FILENO) == 1)
			prompt();

	}
	free(comm);
	if (isatty(STDIN_FILENO) == 1)
		kl_print('\n');
	return (0);
}
