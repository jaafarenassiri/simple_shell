#include "shell.h"

/**
 * _myhst --> displays the history list command by line preceded
 *              with line numbers starting at 0
 * @inf: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhst(info_t *inf)
{
	print_list(inf->history);
	return (0);
}

/**
 * unset_alias1 --> sets alias to string
 * @inf: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1  error
 */
int unset_alias1(info_t *inf, char *str)
{
	char *w, c;
	int ret;

	w = _strchr(str, '=');
	if (!w)
		return (1);
	c = *w;
	*w = 0;
	ret = delete_node_at_index(&(inf->alias),
		get_node_index(inf->alias, node_starts_with(inf->alias, str, -1)));
	*w = c;
	return (ret);
}

/**
 * set_alias1 --> sets alias to -- string--
 * @inf: parameter structure
 * @str: the string alias
 *
 * Return: Always 0 on success, 1  error
 */
int set_alias1(info_t *inf, char *str)
{
	char *w;

	w = _strchr(str, '=');
	if (!w)
		return (1);
	if (!*++w)
		return (unset_alias(inf, str));

	unset_alias1(inf, str);
	return (add_node_end(&(inf->alias), str, 0) == NULL);
}

/**
 * printf_alias --> prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 error
 */
int printf_alias(list_t *node)
{
	char *w = NULL, *a = NULL;

	if (node)
	{
		w = _strchr(node->str, '=');
		for (a = node->str; a <= w; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(w + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalia12 --> mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalia12(info_t *inf)
{
	int i = 0;
	char *w = NULL;
	list_t *node = NULL;

	if (inf->argc == 1)
	{
		node = inf->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; inf->argv[i]; i++)
	{
		w = _strchr(inf->argv[i], '=');
		if (p)
			set_alias1(inf, inf->argv[i]);
		else
			printf_alias(node_starts_with(inf->alias, inf->argv[i], '='));
	}

	return (0);
}

