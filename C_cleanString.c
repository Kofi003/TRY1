#include "shell.h"

/**
 * C_cleanString - erase begin spaces and ending spaces from string
 *
 * @prmString: string to clean
 *
 * Return: clean string
 */
char *C_cleanString(char *prmString)
{
	int cLoopStart = 0, cLoopEnd = 0, size = 0;
	char *string;

	if (prmString == NULL)
		return (NULL);

	size = S_strlen(prmString);

	while (I_inArray(prmString[cLoopStart], " ") == 1)
		cLoopStart++;

	cLoopEnd = size - 1;
	while (I_inArray(prmString[cLoopEnd], " ") == 1)
		cLoopEnd--;
	cLoopEnd = size - 1 - cLoopEnd;

	string = C_calloc(sizeof(char), size - cLoopStart - cLoopEnd + 1);
	S_strncpy(string, (prmString + cLoopStart), size - cLoopStart - cLoopEnd);
	string[size - cLoopStart - cLoopEnd] = '\0';

	/**prmString = *string;*/
	prmString = R_realloc(
		prmString,
		size,
		sizeof(char) * (size - cLoopStart - cLoopEnd + 1)
	);
	S_strcpy(prmString, string);
	prmString[size - cLoopStart - cLoopEnd] = '\0';
	free(string);
	return (prmString);
}
