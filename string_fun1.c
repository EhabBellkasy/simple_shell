#include "shell.h"


/**
 *_putstr - a function to put a string
 *@s: array of characters (string)
 * Return: Nothing.
 */

void _putstr(char *s)
{
int i;

for (i = 0; s[i]; i++)
write(STDERR_FILENO, &s[i], 1);
}


/**
 * concate_string - a function to copy string to another.
 * @s1: first string .
 * @s2: second string.
 * Return: the finals string (s).
 */

char *concate_string(char *s1, char *s2)
{
int i, j, k;
char *s;

for (i = 0; s1[i]; i++)
;
for (j = 0; s2[j]; j++)
;
s = (char *)malloc(sizeof(char) * (i + j + 1));
if (s == NULL)
return (NULL);
for (k = 0; k < i; k++)
s[k] = s1[k];
for (k = 0; k < j; k++)
s[k + i] = s2[k];
s[i + j] = '\0';
return (s);
}


/**
 *_putchar - a function to put a character
 *@c: character to put.
 *Return : nothin;
 */

void _putchar(char c)
{
write(STDERR_FILENO, &c, 1);
}

/**
 *_strlen - a function to count the array of char length
 *@s: array of characters (string)
 *Return: length
 */

int _strlen(char *s)
{
int i;

for (i = 0; s[i]; i++)
;
return (i);
}

