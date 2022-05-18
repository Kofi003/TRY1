#include "shell.h"

/**
 * G_getenvIndex - return index of an environment variable
 *
 * @prmHead: first node
 * @prmName: name
 *
 * Return: index
 */
int G_getenvIndex(environment_t *prmHead, char *prmName)
{
	if (prmHead == NULL || S_strcmp(prmHead->name, prmName) == 0)
		return (0);
	else
		return (G_getenvIndex(prmHead->next, prmName) + 1);
}
