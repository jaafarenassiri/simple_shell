#include "shell.h"

/**
 * _menv --> prints the current environment
 * @inf: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _menv(info_t *inf)
{
	print_list_str(inf->env);
	return (0);
}

/**
 * _genv --> gets the value of an environ variable
 * @inf: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 -- Return: the value
 */
char *_genv(info_t *inf, const char *name)
{
	list_t *node = inf->env;
	char *w;

	while (node)
	{
		w = starts_with(node->str, name);
		if (w && *w)
			return (w);
		node = node->next;
	}
	return (NULL);
}

/**
 * _msetenv --> Initialize a new environment variable,
 *             or modify an existing one
 * @inf: Structure containing potential arguments used to maintain
 *        constant function prototype.
 -- Return: Always 0
 */
int _msetenv(info_t *inf)
{
	if (inf->argc != 3)
	{
		_eputs("Incorrect ---> number of arguements\n");
		return (1);
	}
	if (_setenv(inf, inf->argv[1], inf->argv[2]))
		return (0);
	return (1);
}

/**
 * _munsetenv --> Remove an environment variable
 * @inf: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _munsetenv(info_t *inf)
{
	int i;

	if (inf->argc == 1)
	{
		_eputs("Too few arguement\n");
		return (1);
	}
	for (i = 1; i <= inf->argc; i++)
		_unsetenv(inf, inf->argv[i]);

	return (0);
}

/**
 * --populate_envlist - populates env linked list
 * @inf: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_envlist(info_t *inf)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	inf->env = node;
	return (0);
}

