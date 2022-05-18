#include "shell.h"

/**
 * M_memset - fills the first n bytes of the memory area pointed to by s
 *           with the constant byte b
 *
 * @prmString: pointer to memory area
 * @prmCharacter: constant
 * @prmLimit: number ot bytes to fill
 *
 * Return: write n bytes of value b
 */
char *M_memset(char *prmString, char prmCharacter, unsigned int prmLimit)
{
	unsigned int cLoop;

	for (cLoop = 0; cLoop < prmLimit; cLoop++)
	{
		prmString[cLoop] = prmCharacter;
	}

	return (prmString);
}
