#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdint.h>
#include <linux/limits.h>
#include <limits.h>
#include <signal.h>

int ch_exe(char *file);
int child_creat(char *cmd, char **av);
char *_strdup(char *str);
int _strcmp(char *x, char *y);
int order_chose(char **string_read, char **argv,
unsigned int count_num, int er, char **simi);
void array2d_free(char **array);
void exit_free(char **str, int numExit);
char **get_argv(char *string_read);
char **directory_get(char *path);
char *concate_string(char *s1, char *s2);
char *path_ch(char *file, char **directory);
char *_getenv(const char *key);
int rezise(char *str, ssize_t numchar);
char *strtokMod(char *str, const char *delim);
unsigned int check_delim(char c, const char *str);
void getEnv(void);
void _putstr(char *s);
int _strlen(char *s);
int _putnum(unsigned int num);
int ch_empty(char *buffer);
char *read_line(void);
void youssef (int i,int j,int k,int size ,char *path_val);
int file_exe(char *cmd, char **av, char *argv, int count_num);
void _putchar(char c);
int error_print(char *argv, unsigned int count, char *av, char *prompt);
void done (char *path, char *token ,char **directory, int size);
int do_work (int status);
char **semi_get(char *string_read);
int main(__attribute__((unused)) int argc, char *argv[]);

#endif
