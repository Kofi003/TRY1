#include "shell.h"

/**
 * G_getenv - get environment variable
 *
 * @prmEnviron: first node
 * @prmName: environment variable name
 *
 * Return: environment variable node
 */
environment_t *G_getenv(environment_t *prmEnviron, char *prmName)
{
	if (prmEnviron == NULL)
		return (NULL);

	if (S_strcmp(prmEnviron->name, prmName) == 0)
		return (prmEnviron);

	return (G_getenv(prmEnviron->next, prmName));
}
