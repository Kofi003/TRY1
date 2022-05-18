#include "shell.h"

/**
 * I_isdigit - test if a character is a number
 *
 * @prmChar: char
 *
 * Return: return 1 if true
 */
int I_isdigit(char prmChar)
{
	return (prmChar >= '0' && prmChar <= '9');
}
