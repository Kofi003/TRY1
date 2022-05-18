#include "shell.h"

/**
 * S_strcat - concatenates two string
 *
 * @prmDest: char pointer
 * @prmSrc: char pointer
 *
 * Return: string
 */
char *S_strcat(char *prmDest, char *prmSrc)
{
	int length, d_size, s_size;

	d_size = S_strlen(prmDest);
	s_size = S_strlen(prmSrc);

	for (length = 0; length < s_size; length++)
	{
		prmDest[d_size + length] = prmSrc[length];
	}

	return (prmDest);
}
