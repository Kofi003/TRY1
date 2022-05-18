#include "shell.h"

/**
 * I_inArray - Search a character in an array
 *
 * @prmChar: character to search
 * @prmArray: character array where to search
 *
 * Return: true if success
 */
int I_inArray(char prmChar, char *prmArray)
{
	int cLoop;

	if (prmArray == NULL)
		return (0);

	for (cLoop = 0; prmArray[cLoop] != '\0'; cLoop++)
		if (prmArray[cLoop] == prmChar)
			return (1);

	return (0);
}
