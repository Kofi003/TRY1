#include "shell.h"

/**
 * C_changeToAnyDirectory - change to any directory
 *
 * @prmData: data structure
 * @prmCurrentDirectory: current directory path
 */
void C_changeToAnyDirectory(appData_t *prmData, char *prmCurrentDirectory)
{
	char *newDirectory;

	newDirectory = prmData->arguments[1];

	if (access(newDirectory, R_OK | W_OK) == 0)
	{
		chdir(newDirectory);
		/* set old path environment variable */
		S_setenv(prmData->env, "OLDPWD", prmCurrentDirectory, 1);
	}
	else
		perror(newDirectory);
}
