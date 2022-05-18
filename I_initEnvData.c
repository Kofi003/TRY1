#include "shell.h"

/**
 * I_initEnvData - init environment linked list
 *
 * @prmData: data structre
 */
void I_initEnvData(appData_t *prmData)
{
	int cLoop = 0;
	environment_t *new;

	if (prmData == NULL)
		return;

	while (environ[cLoop] != NULL)
	{
		new = A_addEnvNodeEnd(&prmData->env, environ[cLoop]);

		if (new == NULL)
		{
			free(prmData->env);
			prmData->env = NULL;
			return;
		}

		cLoop++;
	}
}
