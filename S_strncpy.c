#include "shell.h"

/**
 * S_strncpy - copies a string
 *
 * @prmDest: char pointer
 * @prmSrc: char pointer
 * @prmLimit: number of character
 *
 * Return: string
 */
char *S_strncpy(char *prmDest, char *prmSrc, int prmLimit)
{
	int length, size_s;

	size_s = S_strlen(prmSrc);

	for (length = 0; length < prmLimit; length++)
	{
		prmDest[length] = (length <= size_s) ? prmSrc[length] : '\0';
	}

	return (prmDest);
}
