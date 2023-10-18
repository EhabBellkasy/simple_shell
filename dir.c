#include "shell.h"

/**
 * done - a function to get the directory we want.
 * @path: path of the file.
 * @token: what we tokenize.
 * @directory: the dir .
 * @size :size of token.
 * Return: the path we want.
 */

void done(char *path, char *token, char **directory, int size)
{
int i;

for (i = 0; i < size - 1; i++)
{
token = strtok((i ? NULL : path), ":");
directory[i] = _strdup(token);
if (directory[i] == NULL)
{
for (i--; i >= 0; i--)
free(directory[i]);
free(directory);
exit(EXIT_FAILURE);
}
}
}
/**
 * directory_get - a function to get the directory we want.
 * @path: path of the file.
 * Return: the path we want.
 */

char **directory_get(char *path)
{
char **directory = NULL, *token = NULL, *tmp, *tok_temp;
int size = 0;

tmp = _strdup(path);
if (tmp == NULL)
exit(EXIT_FAILURE);
tok_temp = strtok(tmp, ":");
while (tok_temp != NULL)
{
tok_temp = strtok(NULL, ":");
size++;
}

free(tmp), size++;
directory = (char **)malloc(sizeof(char *) * size);
if (directory == NULL)
exit(EXIT_FAILURE);
done(path, token, directory, size);

directory[size - 1] = NULL;
return (directory);
}
