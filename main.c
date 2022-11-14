#include "main.h"

/**
 * main - main entry point of the program
 * @ac: count of command line arguments
 * @av: vector of command line arguments
 *
 * Description: first version (version 0.1) of the simple shell
 * program (ALX SE project)
 * Return: Always 0 (Success)
 */
int main(int ac, char **av)
{
	char *word, *command, *line = NULL, **args = NULL, **env = environ;
	size_t temp, size = 1, n = 0;
	ssize_t num_char;
	void (*func)(char **, char **);

	if (ac != 1)
		return (1);
	while (1)
	{
		do {
			_puts("#cisfun$ ");
			num_char = my_getline(&line, &n, STDIN_FILENO);
			if (num_char == -1)
			{
				free(line), exit(1);
			} line[num_char - 1] = '\0';
		} while (_strcmp(line, "\0") == 0);
		args = malloc(sizeof(char *) * size);
		if (args == NULL)
		{
			errno = ENOMEM, perror("Error");
			free(line);
			exit(1);
		} word = _strtok(line, " ");
		while (word != NULL)
		{
			args[size - 1] = _strdup(word), temp = size, size++;
			args = _realloc(args, sizeof(char *) * temp, sizeof(char *) * size);
			word = _strtok(NULL, " ");
		}
		args[size - 1] = NULL, command = get_command(args[0]), word = args[0];
		args[0] = command, free(word), func = get_func(args[0]);
		if (func == NULL)
			errno = ENOENT, perror(av[0]);
		else
			func(args, env);
		free_args(args), size = 1, args = NULL;
	}
	return (0);
}
