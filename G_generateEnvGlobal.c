#include "shell.h"

/**
 * G_generateEnvGlobal - generate a global environment variable
 *                      from name and value
 *
 * @prmName: environment name
 * @prmValue: environment value
 *
 * Return: global environment variable
 */
char *G_generateEnvGlobal(char *prmName, char *prmValue)
{
	char *tmp, *global;

	global = "";
	global = S_strconcat(global, prmName);
	tmp = S_strconcat(global, "=");
	free(global);
	global = S_strconcat(tmp, prmValue);
	free(tmp);

	return (global);
}
