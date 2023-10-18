#include "shell.h"

/** function to tokenize input string */

/**
 * _strtok - function that tokenizes input string
 * @comm: input command string from user
 * @delim: delimeter for tokenized string
 *
 * Return: tokenized string
 */

char **_strtok(const char *comm, const char *delim)
{
	char **tokens = NULL;
	size_t buff_size = 0, len = 0, new_size;
	char *tok = strtok(comm, delim);
	
	if (comm == NULL || delim == NULL)
	{
		perror("./hsh");
		return (NULL);
	}
	while (tok)
	{
		if (len >= buff_size)
		{
			if (buff_size == 0)
				new_size = 1;
			else
				new_size = buff_size * 2;
			char **new_tokens = _realloc(tokens, buff_size, new_size);
			
			if (new_tokens == NULL)
			{
				perror("Memory allocation error");
				free(tokens);
				return (NULL);
			}
			tokens = new_tokens;
			buff_size = new_size;
		}
		tokens[len] = strdup(tok);
		
		if (tokens[len] == NULL)
		{
			perror("Memory allocation error");
			break;
		}
		tok = strtok(NULL, delim);
		len++;
	}
	tokens = _realloc(tokens, (len + 1) * sizeof(char *));
	
	if (tokens)
		tokens[len] = NULL;
	else
		perror("Memory allocation error");
	return (tokens);
}
