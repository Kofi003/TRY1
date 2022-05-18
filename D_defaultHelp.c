#include "shell.h"

/**
 * D_defaultHelp - print help when any command found
 *
 * @prmCommand: command name
 */
void D_defaultHelp(char *prmCommand)
{
	P_puts("bash: help: Aucune rubrique d'aide ne correspond à \"");
	P_puts(prmCommand);
	P_puts("\". Essayez \"help help\", \"man -k ");
	P_puts(prmCommand);
	P_puts("\" ou \"info ");
	P_puts(prmCommand);
	P_puts("\".\n");
}
