#include "shell.h"

/**
 * F_freeAppData - free all pointer of the appllication
 *
 * @prmData: data structure
 */
void F_freeAppData(appData_t *prmData)
{
	if (prmData == NULL)
		return;

	if (prmData->arguments != NULL)
		F_freeCharDoublePointer(prmData->arguments);
	prmData->arguments = NULL;
	if (prmData->buffer != NULL)
		free(prmData->buffer);
	prmData->buffer = NULL;
	if (prmData->commandName != NULL)
		free(prmData->commandName);
	prmData->commandName = NULL;
	if (prmData->commandList != NULL)
		F_freeCharDoublePointer(prmData->commandList);
	prmData->commandList = NULL;
	if (prmData->history != NULL)
		F_freeCharDoublePointer(prmData->history);
	prmData->history = NULL;
	/*if (prmData->env != NULL)
		F_freeEnvList(prmData->env);
	prmData->env = NULL;*/
	/*if (prmData != NULL)
		free(prmData);
	prmData = NULL;*/
}
