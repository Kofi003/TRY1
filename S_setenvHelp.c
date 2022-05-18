#include "shell.h"

/**
 * SS_setenvHelp - print help for setenv command
 */
void SS_setenvHelp(void)
{
	P_puts("setenv: setenv [VARIABLE] [VALUE]\n");
	P_puts("    Initializes a new environment variable, ");
	P_puts("    or modifies an existing one.\n\n");
	P_puts("    VARIABLE must not have the character '='.\n");
	P_puts("    If no arguments are given, setenv prints ");
	P_puts("    the current environment.\n");
}
