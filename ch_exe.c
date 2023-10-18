#include "shell.h"

/**
 * ch_exe - check if the file is executable or not.
 * @file: the file we want to check.
 *
 * Return: 1 if executable, 0 if not  executable, -1 if error.
*/

int ch_exe(char *file)
{
struct stat s_b;
int slash = 0, i = 0;

while (file[i])
{
if (file[i] == '/')
{
slash = 1;
break;
}

i++;
}

if (stat(file, &s_b) == 0 && s_b.st_mode & S_IXUSR && slash)
return (1);
else if (stat(file, &s_b) == 0 && slash)
return (0);
return (-1);
}
