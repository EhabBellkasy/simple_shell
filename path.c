#include "shell.h"

/**
 *path_ch - a function to check the path if correct or not.
 *@file: path of the file.
 *@directory: list of directories.
 *Return: the path we want.
 */

char *path_ch(char *file, char **directory)
{
struct stat sb;
int i = 0;
char *concat, *concat_path;

concat = concate_string("/", file);
if (concat == NULL)
{
exit(EXIT_FAILURE);
}

for (i = 0; directory[i]; i++)
{
concat_path = concate_string(directory[i], concat);
if (concat_path == NULL)
{
free(concat);
exit(EXIT_FAILURE);
}

if (stat(concat_path, &sb) == 0 && sb.st_mode & S_IXUSR)
{
free(concat);
return (concat_path);
}

free(concat_path);
}

free(concat);
return (NULL); /*no path was found */
}
