#include "shell.h"

/**
 * G_getenvname - return environment name
 *
 * @prmVariable: environment name
 *
 * Return: environment name
 */
char *G_getenvname(char *prmVariable)
{
	char **tmp, *name;

	tmp = S_strtow(prmVariable, ENV_SEPARATOR, NULL);

	if (tmp == NULL)
		return (NULL);

	name = S_strdup(tmp[0]);
	F_freeCharDoublePointer(tmp);
	tmp = NULL;

	return (name);
}
