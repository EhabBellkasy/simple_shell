#include "shell.h"

/**
 * semi_get - a function to check if the input is empty or not.
 * @string_read: the input string we read.
 * Return: NULL if not success, array if success.
 */

char **semi_get(char *string_read)
{
char **argv = NULL, *token, *tmp, *tok_temp;
int size = 0, i;

if (string_read[0] == ' ' && string_read[_strlen(string_read)] == ' ')
exit(0);
if (string_read == NULL)
return (NULL);
tmp = _strdup(string_read);
if (tmp == NULL)
return (NULL);
tok_temp = strtok(tmp, ";&");
while (tok_temp != NULL)
{
size++;
tok_temp = strtok(NULL, ";&");
}
free(tmp), size++;
argv = (char **) malloc(sizeof(char *) * size);
if (argv == NULL)
return (NULL);
for (i = 0; i < size - 1; i++)
{
token = strtok((i ? NULL : string_read), ";&");
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
