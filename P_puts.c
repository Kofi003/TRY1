#include "shell.h"

/**
 * P_puts - write all char from string to stdout
 *
 * @prmStr: string to print
 *
 * Return: number of printed char
 */

int P_puts(char *prmStr)
{
	int i = 0, sum = 0;

	while (prmStr[i])
	{
		sum += _putchar(prmStr[i]);
		i++;
	}
	return (sum);
}
