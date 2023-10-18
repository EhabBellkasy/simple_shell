#include "shell.h"

/**
 *order_chose - chose the order we want to execute.
 *@string_read: the command we typed.
 *@argv: It's commonly used to pass command-line arguments.
 *@count_num: count the number of errors in the shell.
 *@er: the number of errors we did.
 *@si: the array of the silar commands.
 *Return: 0 if success, 2 if error, 127 if not found.
**/

int order_chose(char **string_read, char **argv,
unsigned int count_num, int er, char **si)
{
int stat;
int error = er;

if (_strcmp(string_read[0], "exit") == 0)
{
array2d_free(si);
array2d_free(string_read);
exit(2);
}
else if (_strcmp(string_read[0], "env") == 0)
{
unsigned int index;

for (index = 0; __environ[index] != NULL; index++)
{
printf("%s\n", __environ[index]);
}
return (0);
}
else
{
stat = file_exe(string_read[0],
string_read, argv[0], count_num);
error = errno = stat;
if (stat == -1)
exit_free(string_read, 1);
else if (stat == 127 && !isatty(0))
{
array2d_free(si);
exit_free(string_read, 127);
}
}

return (error);
}
