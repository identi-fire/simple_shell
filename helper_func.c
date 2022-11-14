#include "main.h"


/**
 * free_args - frees up the memory allocated to an array of strings
 * @args: dynamically allocated array of stringsy
 *
 * Return: void
 */
void free_args(char **args)
{
	size_t i;

	if (args == NULL)
		return;
	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args);
}


/**
 * get_command - derives the command from a pathname
 * @str: pathname we wish to parse
 *
 * Return: pointer to the command string
 */
char *get_command(char *str)
{
	size_t temp, size = 1;
	char *string, *command, *token, **args = NULL;

	if (str == NULL)
		return (NULL);
	string = _strdup(str);
	args = malloc(sizeof(char *) * size);
	token = _strtok(string, "/");
	while (token != NULL)
	{
		args[size - 1] = _strdup(token);
		temp = size, size++;
		args = _realloc(args, sizeof(char *) * temp, sizeof(char *) * size);
		token = _strtok(NULL, "/");
	}
	args[size - 1] = NULL;
	command = _strdup(args[size - 2]);
	free_args(args);
	free(string);
	return (command);
}

/**
 * my_getline - alternative to the standard getline function
 * @line: stores the line of text that we read
 * @len: length of the line of text read
 * @fd: file descriptor
 *
 * Return: number of characters read (success) or -1 (error)
 */
ssize_t my_getline(char **line, size_t *len, int fd)
{
	char buffer[30];
	size_t old_len, n, num = 0;

	fflush(stdout);
	if (line == NULL || len == NULL)
	{
		errno = EINVAL, perror("Error");
		return (-1);
	}
	if (*line == NULL)
	{
		*len = sizeof(buffer), *line = malloc(*len + 1);
		if (*line == NULL)
		{
			errno = ENOMEM, perror("Error");
			return (-1);
		}
	}
	(*line)[0] = '\0';
	while ((n = read(fd, &buffer, sizeof(buffer))) != 0)
	{
		if (*len - strlen(*line) < sizeof(buffer))
		{
			old_len = *len, *len *= 2, *line = _realloc(*line, old_len + 1, *len + 1);
			if (*line == NULL)
			{
				errno = ENOMEM, perror("Error");
				free(*line);
				return (-1);
			}
		}
		_strncat(*line, buffer, n);
		num += n;
		if ((*line)[num - 1] == '\n')
		{
			(*line)[num] = '\0';
			return ((ssize_t) _strlen(*line));
		}
	} free(*line), *line = NULL;
	return (-1);
}

