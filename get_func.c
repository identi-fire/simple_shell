#include "main.h"

/**
 * get_func - returns the appropriate function pointer based on input
 * @s: string passed as a parameter
 *
 * Return: function pointer
 */
void (*get_func(char *s))(char **, char **)
{
	options ops[] = {
		{"ls", _list},
		{"exit", my_exit},
		{"env", print_env},
		{NULL, NULL}};
	int i;

	for (i = 0; ops[i].command != NULL; i++)
		if (_strcmp(ops[i].command, s) == 0)
			return (ops[i].func);
	return (NULL);
}
