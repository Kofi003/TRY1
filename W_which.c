#include "shell.h"

/**
 * W_which - return absolute path of a command
 *
 * @prmData: app data structure
 *
 * Return: absolute path
 */
char *W_which(appData_t *prmData)
{
	char **pathList, *absolutePath;
	struct stat st;
	int cLoop = 0;

	if (
		prmData->commandName[0] == '.' &&
		prmData->commandName[1] == '/' &&
		stat(prmData->commandName, &st) == 0
	)
		return (prmData->commandName);

	pathList = P_parsingPathEnvironment(prmData);

	if (pathList == NULL)
		return (NULL);

	while (pathList[cLoop] != NULL)
	{
		absolutePath = G_generateAbsolutePath(pathList[cLoop], prmData->commandName);

		/* Check if absolute path exist */
		if (stat(absolutePath, &st) == 0)
		{
			F_freeCharDoublePointer(pathList);
			return (absolutePath);
		}
		free(absolutePath);
		cLoop++;
	}
	F_freeCharDoublePointer(pathList);

	/* Try to find the command */
	if (stat(prmData->commandName, &st) == 0)
	{
		return (prmData->commandName);
	}
	else
		E_errorHandler(prmData, 101);

	return (NULL);
}
