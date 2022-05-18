#include "shell.h"

/**
 * G_getenvvalue - return environment value
 *
 * @prmVariable: environment name
 *
 * Return: environment value
 */
char *G_getenvvalue(char *prmVariable)
{
	char **tmp, *name;

	tmp = S_strtow(prmVariable, ENV_SEPARATOR, NULL);

	if (tmp == NULL)
		return (NULL);

	name = S_strdup(tmp[1]);
	F_freeCharDoublePointer(tmp);
	tmp = NULL;

	return (name);
}
