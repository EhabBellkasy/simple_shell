#include "shell.h"

/**
 * ch_empty - a function to check if the input is empty or not.
 * @string_read: the input string we read.
 * Return: 0 if not empty, 1 if empty.
 */

int ch_empty(char *string_read)
{
int i;

if (string_read[0] == '\0' || _strcmp(string_read, "\n") == 0)
return (1);

for (i = 0; string_read[i]; i++)
if (string_read[i] != ' ' &&
string_read[i] != '\t' && string_read[i] != '\n')
return (0);

return (1);
}
