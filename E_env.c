#include "shell.h"

/**
 * E_env - print environement variable
 *
 * @prmData: data structure
 */
void E_env(appData_t *prmData)
{
	P_printenv(prmData->env);
}
