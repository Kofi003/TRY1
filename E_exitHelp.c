#include "shell.h"

/**
 * E_exitHelp - print help for exit command
 */
void E_exitHelp(void)
{
	P_puts("exit: exit [n]\n");
	P_puts("    Exit the shell.\n\n");
	P_puts("    Exits the shell with a status of N.  ");
	P_puts("    If N is omitted, the exit status\n");
	P_puts("    is that of the last command executed.\n");
}
