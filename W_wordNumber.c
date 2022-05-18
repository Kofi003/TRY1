#include "shell.h"

/**
 * W_wordNumber - returns word number
 *
 * @prmString: char pointer
 * @prmSeparators: separators
 *
 * Return: Word number
 */
int W_wordNumber(char *prmString, char *prmSeparators)
{
	int cLoop = 0, count = 0;

	while (prmString[cLoop] != '\0')
	{
		if (
			(
				I_inArray(prmString[cLoop], prmSeparators) != 1 ||
				prmString[cLoop] != '\0'
			 ) &&
			(
				I_inArray(prmString[cLoop + 1], prmSeparators) == 1 ||
				prmString[cLoop + 1] == '\0'
			)
		)
			count++;
		cLoop++;
	}

	return (count);
}
