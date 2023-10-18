#include "shell.h"
#include <stdlib.h>
#include <stddef.h>

/** function to reallocate a memory block */

/**
 * *_realloc - function that reallocates a memory block
 * @ptr: pointer to the memory previously allocated
 * @old_ms: size of the allocated memory for ptr
 * @new_ms: size of the new memory block
 *
 * Return: pointer to the newly allocated memory block
 */
void *_realloc(void *ptr, unsigned int old_ms, unsigned int new_ms)
{
	char *ptr1;
	char *pre_ptr;
	unsigned int l;

	if (new_ms == old_ms)
		return (ptr);

	if (new_ms == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr)
		return (malloc(new_ms));

	ptr1 = malloc(new_ms);
	if (!ptr1)
		return (NULL);

	pre_ptr = ptr;

	if (new_ms < old_ms)
	{
		for (l = 0; l < new_ms; l++)
			ptr1[l] = pre_ptr[l];
	}

	if (new_ms > old_ms)
	{
		for (l = 0; l < old_ms; l++)
			ptr1[l] = pre_ptr[l];
	}

	free(ptr);
	return (ptr1);
}
/** function that copies a memory block */

/**
 * *_memcpy - function that copies a memory block
 * @dest: pointer to destination
 * @src: pointer to source
 * @n: bytes to copy
 *
 * Return: pointer to copied bytes memory location
 */
char *_memcpy(char *dest, char *src, size_t n)
{
	size_t l = 0;
	size_t k = n;

	if (dest == NULL || src == NULL)
		return (NULL);
	for (; l < k; l++)
	{
		dest[l] = src[l];
		n--;
	}
	return (dest);
}

/** function that concatenates 2 strings */

/**
 * *_strcat - function that concatenates 2 strings
 * @dest: pointer destination string
 * @src: pointer to source string
 *
 * Return: Pointer to resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	char *temp = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0')
		*dest++ = *src++;

	*dest = '\0';

	return (temp);
}

/** function that copies a string */

/**
 ** _strcpy - function that copies the string pointed to by src
 * @dest: pointer to destination
 * @src: pointer to source string
 * Return: *dest with copied string
 */
char *_strcpy(char *dest, char *src)
{
	int l, k = 0;

	while (*(src + l) != '\0')
		l++;
	while (k < l)
	{
		dest[k] = src[k];
		k++;
	}
	dest[l] = '\0';
	return (dest);
}

/** function that prints string length */

/**
 * _strlen_rec - function that prints length of a string
 * @s: pointer to string
 * Return: length of a string
 */
int _strlen_rec(const char *s)
{
	int l = 0;

	if (*s)
	{
		l++;
		l += _strlen_rec(s + 1);
	}
	return (l);
}
