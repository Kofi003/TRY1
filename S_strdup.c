#include "shell.h"

/**
 * S_strdup - a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter.
 *
 * @prmString: char pointer to copy
 *
 * Return: a new char pointer
 */
char *S_strdup(char *prmString)
{
	char *string;
	int cLoop;

	if (prmString == NULL)
		return (NULL);

	string = malloc(sizeof(char) * (S_strlen(prmString) + 1));

	if (string == NULL)
		return (NULL);

	for (cLoop = 0; cLoop < S_strlen(prmString) + 1; cLoop++)
		string[cLoop] = prmString[cLoop];

	return (string);
}
