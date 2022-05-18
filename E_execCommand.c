#include "shell.h"

/**
 * E_errorHandler - Execute a command
 *
 * @prmData: app data array
 */
void E_errorHandler(appData_t *prmData)
{
	pid_t child_pid;
	char *command;
	int status;

	if (prmData->commandName == NULL)
		return;

	/* Get the absolute path of the command */
	command = W_which(prmData);

	if (command != NULL)
	{
		if (prmData->commandName != command)
			free(prmData->commandName);
		prmData->commandName = command;
	}
	else
	{
		return;
	}

	/* Create a child */
	child_pid = fork();
	if (child_pid == 0)
	{
		/* Execute command*/
		if (execve(prmData->commandName, prmData->arguments, NULL) == -1)
			E_errorHandler(prmData, 103);
		return;
	}
	else if (child_pid == -1)
	{
		E_errorHandler(prmData, 102);
	}
	else
		waitpid(child_pid, &status, WUNTRACED);
}
