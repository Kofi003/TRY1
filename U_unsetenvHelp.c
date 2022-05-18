#include "shell.h"

/**
 * UU_unsetenvHelp - print help for unsetenv command
 */
void UU_unsetenvHelp(void)
{
	P_puts("unsetenv: unsetenv [VARIABLE]\n");
	P_puts("    Initializes a new environment variable, or ");
	P_puts("    modifies an existing one.\n\n");
	P_puts("    VARIABLE must not have the character '='.\n");
	P_puts("    If no arguments are given, setenv prints the current ");
	P_puts("    environment.\n");
}
