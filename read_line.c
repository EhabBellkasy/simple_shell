#include "shell.h"

/**
 * read_line - a function to reads the input string .
 * Return: the inpute string.
 */

char *read_line()
{
char *string_read = NULL;
size_t num = 0;
ssize_t char_read;

char_read = getline(&string_read, &num, stdin);
if (char_read == -1)
{
free(string_read);
return (NULL);
}

return (string_read);
}

