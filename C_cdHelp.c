#include "shell.h"

/**
 * C_cdHelp - printf help for cd command
 */
void C_cdHelp(void)
{
	P_puts("cd: cd [-L|[-P [-e]] [-@]] [dir]\n    Change the shell working dir");
	P_puts("ectory.\n\n    Change the current directory to DIR.  The default DIR");
	P_puts(" is the value of the\n    HOME shell variable.\n    The variable CDP");
	P_puts("ATH defines the search path for the directory containing\n    DIR.  ");
	P_puts("Alternative directory names in CDPATH are separated by a ");
	P_puts("colon (:).\n    A null directory name is the same as the current dir");
	P_puts("ectory.  If DIR begins\n    with a slash (/), then CDPATH is not use");
	P_puts("d.\n\n    If the directory is not found, and the shell option `cdabl");
	P_puts("e_vars' is set,\n    the word is assumed to be  a variable name.  If");
	P_puts(" that variable has a value,\n    its value is used for DIR.\n\n    O");
	P_puts("ptions:\n        -L      force symbolic links to be followed: resolv");
	P_puts("e symbolic links in\n        DIR after processing instances of `..'");
	P_puts("\n        -P      use the physical directory structure without foll");
	P_puts("owing symbolic\n        links: resolve symbolic links in DIR before");
	P_puts(" processing instances\n        of `..'\n        -e      if the -P o");
	P_puts("ption is supplied, and the current working directory\n        canno");
	P_puts("t be determined successfully, exit with a non-zero status\n        ");
	P_puts("-@  on systems that support it, present a file with extended attrib");
	P_puts("utes\n            as a directory containing the file attributes\n\n");
	P_puts("    The default is to follow symbolic links, as if `-L' were specif");
	P_puts("ied.\n");
	P_puts("    `..' is processed by removing the immediately previous pathname");
	P_puts(" component\n    back to a slash or the beginning of DIR.\n\n");
	P_puts("    Exit Status:\n");
	P_puts("    Returns 0 if the directory is changed, and if $PWD is set succe");
	P_puts("ssfully when\n    -P is used; non-zero otherwise.\n");
}
