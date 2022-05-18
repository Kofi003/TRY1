#include "shell.h"

/**
 * C_checkEndCharacter - check if a string have an end of file character
 *
 * @prmString: string
 *
 * Return: 0 if failed
 *         1 if success
 */
int C_checkEndCharacter(char *prmString)
{
	int cLoop = 0;

	if (prmString == NULL)
		return (0);

	while (!prmString[cLoop])
		cLoop++;

	return (prmString[cLoop] == '\0');
}
