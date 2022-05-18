#include "shell.h"

/**
 * G_generateAbsolutePath - Generate an absolute path from environment variable
 *
 * @prmPath: path environment variable
 * @prmCommandName: command name
 *
 * Return: absolute path
 */
char *G_generateAbsolutePath(char *prmPath, char *prmCommandName)
{
	char *tmp, *path, *absolutePath, lastCharacter;
	int pathValueSize;

	path = S_strdup(prmPath);
	pathValueSize = S_strlen(path);
	lastCharacter = path[pathValueSize - 1];

	if (lastCharacter != '/')
	{
		tmp = path;
		path = S_strconcat(tmp, "/");
		free(tmp);
	}

	tmp = "";
	tmp = S_strconcat(tmp, path);
	absolutePath = S_strconcat(tmp, prmCommandName);
	free(tmp);
	free(path);

	return (absolutePath);
}
