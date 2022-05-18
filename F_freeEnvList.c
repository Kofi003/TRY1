#include "shell.h"

/**
 * F_freeEnvList - free a struct linked list
 *
 * @prmHeadNode: first element
 *
 * Return: frees a list_t list
 */
void F_freeEnvList(environment_t *prmHeadNode)
{
	if (prmHeadNode == NULL)
		return;
	F_freeEnvList(prmHeadNode->next);
	free(prmHeadNode->name);
	prmHeadNode->name = NULL;
	free(prmHeadNode->value);
	prmHeadNode->value = NULL;
	free(prmHeadNode->global);
	prmHeadNode->global = NULL;
	free(prmHeadNode);
}
