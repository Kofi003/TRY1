#include "shell.h"

/**
 * SS_setenvironment - set environment variable
 *
 * @prmData: data's structure
 */
void SS_setenvironment(appData_t *prmData)
{
	if (prmData == NULL)
		return;

	if (prmData->arguments == NULL)
		return;

	if (prmData->arguments[1] == NULL || prmData->arguments[2] == NULL)
		return;

	S_setenv(prmData->env, prmData->arguments[1], prmData->arguments[2], 1);
}
