#include "shell.h"

/**
 * get_argv - a function to get the command we typed using strtok.
 * @string_read: the command we typed.
 * Return: array of chars.
 */

char **get_argv(char *string_read)
{
char **argv = NULL, *token, *tmp, *tok_temp;
int size = 0, i;

tmp = _strdup(string_read);
if (tmp == NULL)
return (NULL);
tok_temp = strtok(tmp, " \t\n");
while (tok_temp != NULL)
{
size++;
tok_temp = strtok(NULL, " \t\n");
}

free(tmp), size++;
argv = (char **)malloc(sizeof(char *) * size);
if (argv == NULL)
return (NULL);
for (i = 0; i < size - 1; i++)
{
token = strtok((i ? NULL : string_read), " \t\n");
argv[i] = _strdup(token);
if (argv[i] == NULL)
{
for (i--; i >= 0; i--)
free(argv[i]);
free(argv);
return (NULL);
}
}

argv[size - 1] = NULL;
return (argv);
}
