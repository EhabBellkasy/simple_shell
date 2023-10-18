#include "shell.h"


/**
 * exit_free - free memory exit.
 * @str: the 2ad array .
 * @numExit: number of exit
 * Return: nothing.
 */

void exit_free(char **str, int numExit)
{
array2d_free(str);
exit(numExit);
}
