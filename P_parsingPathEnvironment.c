#include "shell.h"

/**
 * P_parsingPathEnvironment - split environment variable
 *
 * @prmData: data structure
 *
 * Return: string array
 */
char **P_parsingPathEnvironment(appData_t *prmData)
{
	char **paths;
	environment_t *pathEnvNode;

	pathEnvNode = G_getenv(prmData->env, "PATH");
	paths = S_strtow(pathEnvNode->value, PATH_SEPARATOR, NULL);

	return (paths);
}
