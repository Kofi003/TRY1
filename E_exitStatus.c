#include "shell.h"

/**
 * E_exitStatus - exit status
 *
 * @prmData: data structure
 */
void E_exitStatus(appData_t *prmData)
{
	int code = EXIT_SUCCESS;

	if (prmData == NULL)
		return;

	if (prmData->arguments != NULL)
		code = A_atoi(prmData->arguments[1]);

	if (code < 0 || (prmData->arguments[1] != NULL && !I_isNumber(prmData->arguments[1])))
	{
		E_errorHandler(prmData, 106);
		code = 2;
	}

	F_freeAppData(prmData);
	F_freeEnvList(prmData->env);
	prmData->env = NULL;
	free(prmData);
	exit(code);
}
