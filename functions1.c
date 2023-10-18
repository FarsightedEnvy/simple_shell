#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>

/** function to print a char */

/**
 * kl_print - function that prints a char
 * @c: char to print
 *
 * Return: 1
 */
int kl_print(char c)
{
	return (write(1, &c, 1));
}

/** function to print a prompt */

/**
  *prompt - prints a $ character to stdout
  */
void prompt(void)
{
	constant char *prompt = "$ ";

	while (*prompt)
	{
		write(STDOUT_FILENO, prompt, 1);
		prompt++;
	}
}

/** function to read input from user */

/**
  * read_command - function that reads input from user
  * @comm: buffer to store the input string (command)
  * @k: size of buffer
  * Return: number of bytes read
*/


ssize_t read_command(char **comm, size_t *k)
{
	ssize_t read_result;

	read_result = getline(comm, k, stdin);
	return (read_result);
}

/** function that duplicates a string */

/**
  * _strdup - function that duplicates a string
  * @str: pointer to string
  *
  * Return: pointer to new string
*/

char *_strdup(const char *str)
{
	int k, len;
	char *dupl;

	if (str == NULL)
		return (NULL);

	len = _strlen_recursion(str);
	if (len  == 0)
		return (NULL);
	dupl = malloc(sizeof(char) * len + 1);
	if (dupl == NULL)
		return (NULL);
	for (k = 0; k < len; k++)
	{
		dupl[k] = str[k];
	}
	dupl[k] = '\0';
	return (dupl);
}

