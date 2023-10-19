#include "main.h"

/**
 * _execute - Executes command
 * @text: Given text
 * @argv: Argument list
 * @cmd: Command
 * Return: Integer
 */
int _execute(char **text, char **argv, char *cmd)
{
pid_t child;
int status;

child = fork();
if (child < 0)
{
perror(cmd);
exit(-1);
}
else if (child == 0)
{
execve(cmd, text, environ);
perror(argv[0]);
exit(2);
}
else
{
wait(&status);
if (WIFEXITED(status))
status = WEXITSTATUS(status);
errno = status;
}

return (status);
}

/**
 * _prepare - Prepares the text
 * @text: Given text
 * @attempts: Trials
 * @av: list argument
 * @ls: alias list
 */
void _prepare(char **text, int attempts, char **av, alias_t **ls)
{
int (*builtin)(char **text, int attempts, alias_t **ls);

if (_strcmp(text[0], "exit") == 0)
_exitshell(text, attempts, ls);
builtin = builtins(text[0]);
if (builtin)
builtin(text, attempts, ls);
else
_validator(text, av, attempts, ls);
}

/**
 * _validator - Validates command
 * @text: Given text
 * @argv: Argument ist
 * @attempts: Trials
 * @ls: Alias list
 * Return: Integer
 */
void _validator(char **text, char **argv, int attempts, alias_t **ls)
{
char *cmd = NULL;
int check = 0;
alias_t *temp = *ls;

cmd = text[0];
for (; temp != NULL; temp = temp->next)
if (!_strcmp(temp->name, cmd))
cmd = temp->val;

if (access(cmd, X_OK) == 0 && _strcmp(cmd, "hbtn_ls") == 0 && text[1])
{
_execute(text, argv, cmd);
return;
}

if (cmd[0] != '/' && cmd[0] != '.')
{
check = 1;
cmd = _get_path("PATH", cmd);
}

if (!cmd || (access(cmd, X_OK) == -1))
{
_execute_error(argv[0], attempts, text[0]);
}
else
{
_execute(text, argv, cmd);
if (check)
free(cmd);
}
}

/**
 * _get_path - Gets path
 * @path: Path
 * @cmd: Given commmand
 * Return: Path location
*/
char *_get_path(char *path, char *cmd)
{
char *paths, **dir, *token, *command;
struct stat st;

dir = _fetch_env(path);
if (!dir)
return (NULL);

paths = _strdup(*dir);
token = _strtok(paths, ":");
for (; token != NULL; token = _strtok(NULL, ":"))
{
command = malloc(_strlen(cmd) + _strlen(token) + 2);
if (!command)
return (NULL);

_strcpy(command, token);
_strcat(command, "/");
_strcat(command, cmd);

if (stat(command, &st) == 0)
{
free(paths);
return (command);
}
free(command);
}
free(paths);

return (NULL);
}

