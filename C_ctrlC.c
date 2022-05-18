#include "shell.h"

/**
 * C_ctrlC - control c managment
 *
 * @prmSignal: signal value
 */
void C_ctrlC(int prmSignal __attribute__((unused)))
{
	P_puts("\n");
	_prompt();
}
