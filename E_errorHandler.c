#include "shell.h"

void E_errorHandler(appData_t *prmData, int messageCode)
{
	int i = 0;

	errorMessage_t errors[] = {
		{00, "Error unknown"},
		{100, "Error reading from Prompt - Zero tokens"},
		{101, "No such file or directory"},
		{102, "FATAL ERROR: UNABLE TO CREATE CHILD PROCESS"},
		{103, "command not found"},
		{104, "FATAL ERROR: NO MEMORY AVAILABLE."},
		{105, "FATAL ERROR: UNABLE TO CREATE CMD LIST"},
		{106, "Illegal number"},
		{999, ""} /* Error Array end condition*/
	};

	P_puts(prmData->programName);
	P_puts(": ");
	P_puts("1");
	P_puts(": ");
	P_puts(prmData->commandName);
	P_puts(": ");
	while (i < 9)
	{
		if (messageCode == (errors + i)->code)
		{
			P_puts((errors + i)->msg);
			P_puts(": ");
			P_puts(prmData->arguments[1]);
		}
		i++;
	}
	P_puts("\n");
}
