#include "main.h"

/**
 * _strdup - duplicates a string in memory
 * @str: string to duplicate
 *
 * Return: pointer to duplicate of the string
 */
char *_strdup(const char *str)
{
	char *new_str;
	size_t i, length;

	if (str == NULL)
		return (NULL);
	length = _strlen(str);
	new_str = malloc(sizeof(char) * (length + 1));
	if (new_str == NULL)
		return (NULL);
	for (i = 0; i < length; i++)
		new_str[i] = str[i];
	new_str[i] = '\0';
	return (new_str);
}


/**
 * _strcpy - copies the contents of one string to another string
 * @dest: destination string
 * @src: source string
 *
 * Return: destination string
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i = 0;

	if (dest == NULL || src == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


/**
 * _strtok - cuts a string into tokens based on a specified delimiter
 * @string: string to be tokenized
 * @delim: string used as delimiter
 *
 * Return: token (Success) or NULL (fail)
 */
char *_strtok(char *string, const char *delim)
{
	static char *input;
	char *token = NULL;
	size_t i = 0;

	if (string != NULL)
		input = string;
	if (input == NULL)
		return (NULL);
	while (input[i] == *delim && input[i] != '\0')
		input = &input[i + 1];
	if (input[i] != '\0')
		token = input;
	while (input[i] != *delim && input[i] != '\0')
		i++;
	if (input[i] != '\0' && input[i + 1] != '\0')
	{
		input[i] = '\0';
		input = &input[i + 1];
	}
	else
	{
		input[i] = '\0';
		input = NULL;
	}
	return (token);
}

/**
 * _strncat - appends a number of character of a string to another
 * @dest: destination string
 * @src: source string
 * @count: specified number
 *
 * Return: pointer to the appended string
 */
char *_strncat(char *dest, const char *src, size_t count)
{
	size_t i = 0, j = 0;

	while (dest[i] != '\0')
		i++;

	while (j < count && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';

	return (dest);
}
