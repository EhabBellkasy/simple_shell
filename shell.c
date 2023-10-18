#include "shell.h"


/**
 * main - a main function.
 * @argc: size of an args array.
 * @argv: array of arguments.
 * Return: stats if success.
 */

int main(__attribute__((unused)) int argc, char *argv[])
{
char *string_read = NULL, **strRead_cp, *wt = "shell", **simiColon;
unsigned int count_num = 0, i;
int stat = 0, err = 0;

while (++count_num)
{
if (isatty(0))
write(STDOUT_FILENO, wt, 5);
string_read = read_line();
if (string_read == NULL) /*Exsit Imput or not */
exit(err);
if (ch_empty(string_read))
{
free(string_read);
continue;
}
simiColon = semi_get(string_read);
free(string_read);
if (simiColon == NULL)
array2d_free(simiColon), exit(1);
for (i = 0; simiColon[i] != NULL; i++)
{
strRead_cp = get_argv(simiColon[i]);
if (strRead_cp == NULL) /* if return NULL */
{
array2d_free(strRead_cp);
exit_free(simiColon, 1);
}
if (strRead_cp[0] == NULL)
{
stat = 0, array2d_free(strRead_cp);
continue;
}
stat = order_chose(strRead_cp, argv, count_num, err, simiColon);
err = errno = stat;
array2d_free(strRead_cp);
}
array2d_free(simiColon);
}
return (err);
}
