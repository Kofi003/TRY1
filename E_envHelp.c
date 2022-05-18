#include "shell.h"

/**
 * E_envHelp - print help for env command
 */
void E_envHelp(void)
{
	P_puts("env: env\n");
	P_puts("    prints the current environment.\n\n");
	P_puts("    Has no options\n");
}
