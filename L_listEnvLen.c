#include "shell.h"

/**
 * L_listEnvLen - length of a linked list
 *
 * @prmHead: first node
 *
 * Return: length
 */
int L_listEnvLen(environment_t *prmHead)
{
	if (prmHead == NULL)
		return (0);
	if (prmHead->next == NULL)
		return (1);
	else
		return (L_listEnvLen(prmHead->next) + 1);
}
