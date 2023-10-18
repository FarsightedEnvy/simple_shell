#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>

/** function to tokenize input string */

/**
 * _strtok - function that tokenizes input string
 * @comm: input command string from user
 * @delim: delimeter for tokenized string
 *
 * Return: tokenized string
 */
char **_strtok(char *comm, char *delim)
{
	int len = 0, buff_size = 64, pre_size;
	char *tok, **tokens;

	if (comm == NULL)
	{
		perror("./hsh");
		return (NULL);
	}
	if (*comm == '\n')
		return (NULL);
	tokens = malloc(sizeof(char *) * buff_size);

	if (tokens == NULL)
	{
		perror("./hsh");
		return (NULL);
	}
	tok = strtok(comm, delim);

	while (tok)
	{
		tokens[len] = tok;

		if (len >= buff_size)
		{
			pre_size = sizeof(char *) * buff_size;
			tokens = resize_buff(tokens, pre_size);
			
			if (tokens == NULL)
			{
				perror("/hsh");
				return (NULL);
			}
			buff_size += buff_size;
		}
		tok = strtok(NULL, delim);
		len++;
	}
	tokens[len] = NULL;
	return (tokens);
}
