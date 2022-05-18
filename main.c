#include "shell.h"

int main(int argc __attribute__((unused)), char **argv)
{
	appData_t *appData = NULL;
	int cLoop;
	void (*func)(appData_t *);

	appData = I_initData(argv);

	do {
		signal(SIGINT, C_ctrlC);
		_prompt();

		G_getline(appData);

		appData->history = S_strtow(appData->buffer, COMMAND_SEPARATOR, ESCAPE_SEPARATOR);

		if (appData->history == NULL)
		{
			F_freeAppData(appData);
			free(appData);
			continue;
		}

		for (cLoop = 0; appData->history[cLoop] != NULL; cLoop++)
		{
			appData->arguments = S_strtow(appData->history[cLoop], SEPARATORS, ESCAPE_SEPARATOR);

			if (appData->arguments == NULL)
			{
				F_freeAppData(appData);
				F_freeEnvList(appData->env);
				appData->env = NULL;
				free(appData);
				appData = NULL;
				break;
			}

			appData->commandName = S_strdup(appData->arguments[0]);

			if (appData->commandName != NULL)
			{
				func = G_getCustomFunction(appData->commandName);
				if (func != NULL)
					func(appData);
				else
					E_errorHandler(appData);
			}
			F_freeCharDoublePointer(appData->arguments);
			appData->arguments = NULL;
			free(appData->commandName);
			appData->commandName = NULL;
		}

		F_freeAppData(appData);
	} while (1);
	return (EXIT_SUCCESS);
}
