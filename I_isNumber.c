#include "shell.h"

/**
 * I_isNumber - check if string is a number
 *
 * @s: string to verify
 *
 * Return: 1 if string is a number.
 */
int I_isNumber(char *s)
{
	if (*s == '\0')
	{
		return (1);
	}
	if (!I_isdigit(*s))
	{
		return (0);
	}
	else
	{
		return (I_isNumber(s + 1));
	}
}
