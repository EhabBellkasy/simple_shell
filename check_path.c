#include "shell.h"

/**
 * check_path - checks if command exists in path
 * @command: command to check
 * Return: cmd path if found, NULL if not found
*/

char *check_path(char *command)
{
char *path_var, *path, *full_path;
struct stat st;
int i;

for (i = 0; command[i]; i++)
{
if (command[i] == '/')
{
if (stat(command, &st) == 0)
return (strdup(command));
return (NULL);
}
}

path_var = getenv("PATH");
if (!path_var || strlen(path_var) == 0)
return (NULL);

path_var = strdup(getenv("PATH"));

path = strtok(path_var, ":");
while (path)
{
full_path = malloc(strlen(path) + strlen(command) + 2);
strcpy(full_path, path);
strcat(full_path, "/");
strcat(full_path, command);
if (stat(full_path, &st) == 0)
{
free(path_var);
return (full_path);
}

free(full_path);
path = strtok(NULL, ":");
}
free(path_var);
return (NULL);
}
