#include "main.h"

/**
 * _fetch_env - Gets environment variable
 * @env_var: Variable
 * Return: Content
*/

char **_fetch_env(char *env_var)
{
int len = 0, i = 0;

if (!env_var || env_var[0] == '\0')
return (NULL);

len = _strlen(env_var);
for (i = 0; environ[i] != NULL; i++)
if (_strncmp(environ[i], env_var, len) == 0 && environ[i][len] == '=')
return (&environ[i]);

return (NULL);
}

