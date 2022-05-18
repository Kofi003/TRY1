#include "shell.h"

/**
 * S_strlen - return string length
 *
 * @prmStr: string
 *
 * Return: string length
 */
int S_strlen(char *prmStr)
{
	if (prmStr == NULL || *prmStr == '\0')
		return (0);
	return (S_strlen(prmStr + 1) + 1);
}
