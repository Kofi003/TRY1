#include "shell.h"

/**
 * C_changeToHomeDirectory - change to home directory
 *
 * @prmData: data structure
 * @prmCurrentDirectory: current directory path
 */
void C_changeToHomeDirectory(appData_t *prmData, char *prmCurrentDirectory)
{
	environment_t *newDirectory;

	newDirectory = G_getenv(prmData->env, "HOME");

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
