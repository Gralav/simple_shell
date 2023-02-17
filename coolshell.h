#ifndef COOLSHELL_H
#define COOLSHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>

extern char **environ;

char *prompt_n_read(char *path_str, char **array_path);
char **split_buf(char *buf);
int token_count_buf(char *buf);
int fork_n_exec(char *str_buf_path, char **array_buf);
char *_getenv(const char *name);
char **split_path(char *path_str);
int token_count_path(char *path_str);
int _strlen(char *s);
char *buf_path_cat(int counter, char *av, char *array_buf, char **array_path);
int _status(char *str_buf_path);
char *_strcat(char *dest, char *src);
char *_memset(char *s, char b, unsigned int n);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _putchar(char c);
int _print(char *str);
void print_number(int n);
void sig_handler(int signo);

int handle_cmd(char **av, int counter, char **array_buf, char **array_path,
char *str_buf_path);
int handle_path_cmd(char **av, int counter, char **array_buf);
int handle_nopath_cmd(char **array_path, char **av, char **array_buf,
int counter, char *str_buf_path);

/**
 * struct builtins - creates profile with name, and function elements
 * @name: command name
 * @f: function called for the command to be executed
 * Description: creates profile with name, and function elements
 */

typedef struct builtins
{
	char *name;
	void (*f)(char **, char *, char *, char **, int);
} built_ins;

void (*get_builtins_func(char *s))(char **, char *, char *, char **, int);
void env_(char **array_buf, char *buf, char *path_str, char **array_path,
int exit_status);
void exit_(char **array_buf, char *buf, char *path_str, char **array_path,
int exit_status);
void help_(char **array_buf, char *buf, char *path_str, char **array_path,
int exit_status);

#endif
