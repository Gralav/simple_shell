
#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <stddef.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ:
/**
 * struct builtins - Has builtins and associated funcs
 * @arg: Builtins name
 * @builtin: Mathcing builtin func
 */

void shell(int ac, char **av, char **env);
int check_for_builtins(char **args, char *line, char **env);
int builtins_checker(char **args);
int bridge(char *check, char **args);
char *_getenv(char *env)
char *find_path(char *filename, char *tmp, char *er)
char *read_dir(char *er, struct dirent *s, char *fil, int l, char *fp, char *t)
char *save_path(char *tmp, char *path)
void exit_shell(char **args, char *line, char **env)
void env_shell(char **args, char *line, char **env)

