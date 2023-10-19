#include "main.h"

/**
 * builtins - Shell builtins
 * @s: Given string
 * Return: 0
*/
int (*builtins(char *s))(char **text, int attempt, alias_t **ls)
{
builtin_t sys[] = {
{"env", _printenv},
{"alias", _alias},
{NULL, NULL}
};
int i = 0;

while (sys[i].builtin)
{
if (_strcmp(sys[i].builtin, s) == 0)
return (sys[i].func);
i++;
}

return (NULL);
}

/**
 * _exitshell - Exits shell
 * @text: Argument list
 * @count: Count
 * @h: Head alias
 * Return: 0
*/
int _exitshell(char **text, int count, alias_t **h)
{
int status = errno;

if (text[1])
{
status = _atoi(text[1]);
if (status <= 0)
{
_exit_error(count, text[1]);
status = 2;
}
}
_free_alias(h);
free(text);
exit(status);
}

/**
 * _printenv - Prints environment
 * @text: Given text
 * @count: Count
 * @ls: alias list
 * Return: 0
*/
int _printenv(char **text, int count, alias_t **ls)
{
int i;
char newline = '\n';

(void)text;
(void)ls;
(void)count;
if (!environ)
return (-1);
for (i = 0; environ[i]; i++)
{
write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
write(STDOUT_FILENO, &newline, 1);
}

return (0);
}


