#include "shell.h"

/**
 * file_exe - a function to execute the command we typed.
 * @cmd: the command we typed.
 * @av: It's commonly used to pass command-line arguments to the executed.
 * @argv: cointans the file name.
 * @count_num: count the number of errors in the shell command.
 * Return: -1 if there is an error, executed  if not error.
 */

int file_exe(char *cmd, char **av, char *argv, int count_num)
{
char **path_dir = NULL;
char *path_found = NULL, *prompt, *path = _getenv("PATH");
int execute = ch_exe(cmd), isPATH = 0, err = 0;

if (execute == 1)
{
err = child_creat(cmd, av);
if (err == -1)
{
return (-1);
}
}
else if (isPATH == 0 && path != NULL)
{
path_dir = directory_get(path);
/*returns the executable PATH, NULL otherwise */
path_found = path_ch(cmd, path_dir);
if (path_found != NULL)
{
isPATH = 1; /*there is an executable in PATH */
err = child_creat(path_found, av);
if (err == -1)
return (-1);
}
}

if (isPATH == 0 && execute <= 0)
{
prompt = (execute == 0 ? "deny_permission\n" : "not found\n");
err = error_print(argv, count_num, av[0], prompt);
}

if (path)
free(path);
if (path_found)
free(path_found);
if (path_dir)
array2d_free(path_dir);
return (err);
}
