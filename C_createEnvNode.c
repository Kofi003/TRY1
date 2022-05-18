#include "shell.h"

/**
 * C_createEnvNode - create a new node
 *
 * @prmGlobal: global environment value
 *
 * Return: new element
 */
environment_t *C_createEnvNode(char *prmGlobal)
{
	environment_t *new;

	if (prmGlobal == NULL)
		return (NULL);

	new = malloc(sizeof(environment_t));
	if (new == NULL)
		return (NULL);

	new->name = G_getenvname(prmGlobal);
	new->value = G_getenvvalue(prmGlobal);
	new->global = S_strdup(prmGlobal);
	new->next = NULL;

	return (new);
}
