#include "shell.h"

/**
 * S_setenv - set environment value
 *
 * @prmEnviron: environment linked list
 * @prmName: environment name
 * @prmValue: environment value
 * @prmOverwrite: overwrite
 */
void S_setenv(
	environment_t *prmEnviron,
	char *prmName,
	char *prmValue,
	int prmOverwrite
) {
	environment_t *envNode;
	char *tmp;

	if (prmName == NULL || prmValue == NULL)
		return;

	envNode = G_getenv(prmEnviron, prmName);

	if (envNode == NULL)
	{
		tmp = G_generateEnvGlobal(prmName, prmValue);
		A_addEnvNodeEnd(&prmEnviron, tmp);
		free(tmp);
	}
	else if (prmOverwrite == 1)
	{
		free(envNode->value);
		envNode->value = S_strdup(prmValue);
	}
}
