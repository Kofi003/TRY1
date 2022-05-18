#include "shell.h"

/**
 * C_changeDirectory - change current directory
 *
 * @prmData: data structure
 */
void C_changeDirectory(appData_t *prmData)
{
	char currentDirectory[500];

	getcwd(currentDirectory, 500);

	if (prmData == NULL)
		return;

	if (
		!prmData->arguments[1] ||
		S_strcmp(prmData->arguments[1], "~") == 0 ||
		S_strcmp(prmData->arguments[1], "~/") == 0
	)
		C_changeToHomeDirectory(prmData, currentDirectory);
	/* Old path */
	else if (S_strcmp(prmData->arguments[1], "-") == 0)
		C_changeToPreviousDirectory(prmData, currentDirectory);
	else
		C_changeToAnyDirectory(prmData, currentDirectory);
}
