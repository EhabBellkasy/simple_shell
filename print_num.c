#include "shell.h"

/**
 *_putnum - prints unsigned integer
 *@num: number
 *Return: 0 on success, 1 on failure
 */

int _putnum(unsigned int num)
{
unsigned int num_cp = num;
char *num_str;
int i, size = 0;

if (num == 0)
{
_putchar('0');
return (0);
}

while (num_cp)
{
size++;
num_cp /= 10;
}

num_str = (char *)malloc(sizeof(char) * size);
if (num_str == NULL)
{
return (1);
}

i = size - 1;
while (num)
{
num_str[i] = '0' + (num % 10);
num /= 10;
i--;
}

i = 0;
while (i < size)
{
_putchar(num_str[i]);
i++;
}

free(num_str);
return (0);
}
