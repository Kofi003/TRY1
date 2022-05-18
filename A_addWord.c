#include "shell.h"

/**
 * A_addWord - add a word to an array
 *
 * @prmWord: word to add
 * @prmIndex: current index
 * @prmArray: array
 */
void A_addWord(char *prmWord, int *prmIndex, char **prmArray)
{
	prmWord = C_cleanString(prmWord);
	prmArray[*prmIndex] = S_strdup(prmWord);
	free(prmWord);
	*prmIndex += 1;
}
