#include "shell.h"

/**
 * C_changeToPreviousDirectory - change to previous directory
 *
 * @prmData: data structure
 * @prmCurrentDirectory: current directory path
 */
void C_changeToPreviousDirectory(appData_t *prmData, char *prmCurrentDirectory)
{
	environment_t *newDirectory;

	newDirectory = G_getenv(prmData->env, "OLDPWD");

	if (access(newDirectory->value, R_OK | W_OK) == 0)
	{
		chdir(newDirectory->value);
		/* set old path environment variable */
		S_setenv(prmData->env, "OLDPWD", prmCurrentDirectory, 1);
	}
	else
	{
		perror(newDirectory->value);
	}
}
