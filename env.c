#include "shell.h"

/**
 * _getenv - a function to get the enivroment and split it.
 * @key: path of the file.
 * Return: the path_val.
 */

char *_getenv(const char *key)
{
char *path_val = NULL;
int i = 0, j, k, E_q, size;

while (__environ[i])
{
E_q = 1;
/*Split the current environment variable into name and path_val*/
for (j = 0; __environ[i][j] != '=' && key[j]; j++)
{
if (key[j] != __environ[i][j])
E_q = 0;
}

if (E_q)
{
k = 0;
for (size = j; __environ[i][size]; size++)
;
size -= j;
j++;

path_val = (char *)malloc(sizeof(char) * (size + 1));
if (path_val == NULL)
{
free(path_val);
exit(EXIT_FAILURE);
}

for (; __environ[i][j]; j++)
path_val[k] = __environ[i][j], k++;
path_val[k] = '\0';
break;
}

i++;
}

return (path_val);
}
