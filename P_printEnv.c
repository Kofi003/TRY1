#include "shell.h"

/**
 * P_printenv - print environment variables
 *
 * @prmEnviron: environment variable list
 */
void P_printenv(environment_t *prmEnviron)
{
	if (prmEnviron == NULL)
		return;

	P_puts(prmEnviron->name);
	P_puts("=");
	if (prmEnviron->value != NULL)
		P_puts(prmEnviron->value);
	P_puts("\n");
	P_printenv(prmEnviron->next);
}
