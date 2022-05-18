#include "shell.h"

/**
 * A_atoi - convert a string to an integer.
 *
 * @prmString: char pointer
 *
 * Return: int
 */
int A_atoi(char *prmString)
{
	char sign = 1, current;
	int size = S_strlen(prmString), cLoop;
	unsigned int number = 0;

	for (cLoop = 0; cLoop < size; cLoop++)
	{
		current = prmString[cLoop];

		if (I_isdigit(current))
		{
			number *= 10;
			number += current - 48;
		}
		else if (current == '-')
			sign = -sign;
		else if (number > 0)
			break;
	}

	return (sign * number);
}
