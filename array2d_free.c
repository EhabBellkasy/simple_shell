#include "shell.h"

/**
 * array2d_free - free memory for 2d array.
 * @array: the 2ad array .
 * Return: nothing.
 */

void array2d_free(char **array)
{
int i = 0;

while (array[i])
free(array[i]), i++;
free(array);
}

