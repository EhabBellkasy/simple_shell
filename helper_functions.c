#include "main.h"

/**
 * _strlen - Gets length of a string
 * @str: Given string
 * Return: Length
*/
int _strlen(char *str)
{
int count = 0;

if (str == NULL)
return (0);
while (str[count] != '\0')
count++;
return (count);
}

/**
 * _strcpy - Copies string
 * @dest: Destination
 * @src: Source
 *
 * Return: Character
 */
char *_strcpy(char *dest, char *src)
{
int i;

for (i = 0; src[i] != '\0'; i++)
dest[i] = src[i];
dest[i] = '\0';
return (dest);
}

/**
 * _strcmp - Compares two strings
 * @s1: String one
 * @s2: String two
 * Return: Difference
 */
int _strcmp(char *s1, char *s2)
{
unsigned int diff = 0;

while (*s1 != '\0')
{
diff = *s1 - *s2;
if (*s1 != *s2)
break;
s1++;
s2++;
}
return (diff);
}

/**
 * _strcat - Combines strings
 * @dest: Destination
 * @src: Source
 * Return: 0
 */
char *_strcat(char *dest, char *src)
{
int the_dest = _strlen(dest);
int the_src = _strlen(src);
int total = the_dest + the_src;
int i = 0;

for (; the_dest < total; the_dest++)
{
dest[the_dest] = src[i];
i++;
}
dest[total] = '\0';

return (dest);
}

/**
 * _strdup - Duplicates string
 * @s: Given string
 * Return: Duplicate
*/
char *_strdup(char *s)
{
int i = 0, len = _strlen(s);
char *str_dup;

if (!s)
return (NULL);
str_dup = malloc((len + 1) * sizeof(char));
if (!str_dup)
return (NULL);
for (i = 0; s && s[i]; i++)
str_dup[i] = s[i];
str_dup[i] = '\0';

return (str_dup);
}

