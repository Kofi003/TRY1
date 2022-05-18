#include "shell.h"

/**
 * G_getLastEnvNode - get last node
 *
 * @prmHeadNode: first node
 *
 * Return: last element
 */
environment_t *G_getLastEnvNode(environment_t *prmHeadNode)
{
	environment_t *head, *next;

	head = prmHeadNode;

	if (head == NULL)
		return (NULL);

	next = head->next;

	if (next == NULL)
		return (head);
	else
		return (G_getLastEnvNode(next));
}
