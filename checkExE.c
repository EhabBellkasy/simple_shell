#include "shell.h"

/**
 * do_work - create a child process.
 * @status: the command we typed.
 *
 * Return: 0 if success, 2 if error, 127 if not found.
*/
int do_work(int status)
{
if (WIFEXITED(status))
{
errno = WEXITSTATUS(status);
if (WEXITSTATUS(status) == 0)
return (0);
else if (WEXITSTATUS(status) == 127)
return (127);
else if (WEXITSTATUS(status) == 2)
return (2);
}
return (999);
}

/**
 * child_creat - create a child process.
 * @cmd: the command we typed.
 * @av: It's commonly used to pass command-line arguments.
 *
 * Return: 0 if success, 2 if error, 127 if not found.
*/

int child_creat(char *cmd, char **av)
{
pid_t child_pid;
int status, x;
child_pid = fork();
if (child_pid == -1)
{
perror("fork error");
return (-1);
}
else if (child_pid == 0)
{
if (execve(cmd, av, __environ) == -1)
{
perror(av[0]);
errno = 2;
return (2);
}
else
{
errno = 0;
return (0);
}
}
else if (child_pid > 0)
{
wait(&status);
x = do_work(status);
if (x != 999)
return (x);
}

return (127);
}
