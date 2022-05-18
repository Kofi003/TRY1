#include "shell.h"

/**
 * _help - manage command help
 *
 * @prmData: data structure
 */
void _help(appData_t *prmData)
{
	if (prmData == NULL)
		return;
	if (prmData->commandName == NULL)
		return;
	if (
		prmData->arguments == NULL ||
		prmData->arguments[0] == NULL ||
		prmData->arguments[1] == NULL
	)
		return;
	if (S_strcmp(prmData->arguments[1], "cd") == 0)
		C_cdHelp();
	else if (S_strcmp(prmData->arguments[1], "env") == 0)
		E_envHelp();
	else if (S_strcmp(prmData->arguments[1], "setenv") == 0)
		SS_setenvHelp();
	else if (S_strcmp(prmData->arguments[1], "unsetenv") == 0)
		UU_unsetenvHelp();
	else if (S_strcmp(prmData->arguments[1], "exit") == 0)
		E_exitHelp();
	else if (S_strcmp(prmData->arguments[1], "help") == 0)
		_helpHelp();
	else
		D_defaultHelp(prmData->arguments[1]);
}
