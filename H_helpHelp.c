#include "shell.h"

/**
 * H_helpHelp - print help for help command
 */
void H_helpHelp(void)
{
	P_puts("help: help [-dms] [pattern ...]\n");
	P_puts("    Display information about builtin commands.\n\n");
	P_puts("    Displays brief summaries of builtin commands.  If PATTERN is\n");
	P_puts("    specified, gives detailed help on all commands ");
	P_puts("    matching PATTERN,\n");
	P_puts("    otherwise the list of help topics is printed.\n\n");
	P_puts("    Options:\n");
	P_puts("      -d        output short description for each topic\n");
	P_puts("      -m        display usage in pseudo-manpage format\n");
	P_puts("      -s        output only a short usage synopsis for each topic m");
	P_puts("atching\n        PATTERN\n\n");
	P_puts("    Arguments:\n");
	P_puts("      PATTERN   Pattern specifying a help topic\n\n");
	P_puts("    Exit Status:\n");
	P_puts("    Returns success unless PATTERN is not found or an invalid ");
	P_puts("    option is given.\n");
}
