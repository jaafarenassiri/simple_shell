#include "shell.h"

/**
 * interactive ---> return true if shell is interactive mode
	* @inf: --> struct address
 *
 * Return: 1 interactive mode-- 0 otherwise
 */
int interactive(info_t *inf)
{
	return (isatty(STDIN_FILENO) && inf->readfd <= 2);
}

/**
 * is_dlm --> checks if character is a delimeter
 * @c:-> the char to check
 * @delim: the delimeter string
 * Return: 1 true, 0 false
 */
int is_dlm(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalph --> checks for alphabetic character
 * @c: The character to input
 * Return: 1  is alphabetic, 0 otherwise
 */

int _isalph(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi --> converts a string to an integer
 * @n: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *n)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; n[i] != '\0' && flag != 2; i++)
	{
		if (n[i] == '-')
			sign *= -1;

		if (n[i] >= '0' && n[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (n[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
