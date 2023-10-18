#include "shell.h"

/**
 * _strdup - function to duplicate a string.
 * @str: the string we want to duplicate.
 *
 * Return: the string duplicated.
*/

char *_strdup(char *str)
{
char *copy;
int i, size = 0;

if (str == NULL)
return (NULL);

while (str[size] != '\0')
size++;

copy = (char *) malloc((sizeof(char) * size) + 1);
if (copy == NULL)
return (NULL);

for (i = 0; i < size; i++)
copy[i] = str[i];
copy[size] = '\0';

return (copy);
}

/**
 * _strcmp - function to compare two strings.
 * @x: the first string.
 * @y: the second string.
 *
 * Return: 1 if not E_q, 0 if E_q.
*/

int _strcmp(char *x, char *y)
{
int i, j;

for (i = 0; x[i]; i++)
;
for (j = 0; y[j]; j++)
;
if (i != j)
return (1);

for (i = 0; x[i]; i++)
if (x[i] != y[i])
return (1);
return (0);
}
