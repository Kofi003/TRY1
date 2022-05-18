#include "shell.h"

/**
 * G_getCustomFunction - check custom command
 *
 * @prmCommand: command
 *
 * Return: pointer function
 */
void (*G_getCustomFunction(char *prmCommand))(appData_t *)
{
	int i = 0;

	customCommand_t fp[] = {
		{"cd", C_changeDirectory},
		{"env", E_env},
		{"setenv", SS_setenvironment},
		{"unsetenv", UU_unsetenvironment},
		{"exit", E_exitStatus},
		{"help", H_help}
	};

	while (i < 6)
	{
		if (S_strcmp(prmCommand, (fp + i)->commandName) == 0)
			return ((fp + i)->func);
		i++;
	}

	return (NULL);
}
