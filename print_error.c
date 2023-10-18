#include "shell.h"

/**
 *error_print -  function for printing error messages.
 *@argv: the name of the command or executable.
 *@count: error count.
 *@av: coints the file name
 *@prompt: cointains the prompt arg
 *
 *Return: 127 or -1
 */

int error_print(char *argv, unsigned int count, char *av, char *prompt)
{
_putstr(argv);
_putchar(':'), _putchar(' ');
if (_putnum(count))
return (-1);
_putchar(':'), _putchar(' ');
_putstr(av);
_putchar(':'), _putchar(' ');
_putstr(prompt);

return (127);
}
