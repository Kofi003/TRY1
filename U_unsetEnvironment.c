#include "shell.h"

/**
 * UU_unsetenvironment - unset environment variable
 *
 * @prmData: data's structure
 */
void UU_unsetenvironment(appData_t *prmData)
{
	if (prmData == NULL)
		return;

	if (prmData->arguments == NULL)
		return;

	if (prmData->arguments[1] == NULL)
		return;

	U_unsetenv(prmData, prmData->arguments[1]);
}
