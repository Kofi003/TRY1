#include "shell.h"

/**
 * U_unsetenv - unset environment variable
 *
 * @prmData: data structure
 * @prmName: environment name
 */
void U_unsetenv(appData_t *prmData, char *prmName)
{
	D_deleteEnvNode(prmData->env, prmName);
}
