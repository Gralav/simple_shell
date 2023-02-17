#include "coolshell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>

/**
 * main - function that executes command line operations
 * @ac: argument count
 * @av: double pointer, pointer to string of pointers to the command line
 * arguments
 * Return: Always 0
 */

int main(int ac, char **av)
{
	const int n = 1;
	int counter = 0, exit_status = 0;
	char *buf = NULL, **array_buf = NULL, *path = NULL, *path_str = NULL;
	char **array_path = NULL, *str_buf_path = NULL;
	void (*ptr)();

	(void)ac;
	signal(SIGINT, sig_handler);
	path = "PATH";
	path_str = _getenv(path);
	if (path_str == NULL)
		return (-1);
	array_path = split_path(path_str);
	while (n)
	{
		counter++, buf = prompt_n_read(path_str, array_path);
		while (*buf == '\n')
			counter++, free(buf), buf = prompt_n_read(path_str, array_path);
		if (*buf != '\0')
		{
			array_buf = split_buf(buf);
			if (array_buf != NULL && array_buf[0] != NULL)
			{
				ptr = get_builtins_func(array_buf[0]);
				if (ptr != NULL)
				{
					(*ptr)(array_buf, buf, path_str, array_path, exit_status);
					continue;
				}
				else
					exit_status = handle_cmd(av, counter, array_buf,
								 array_path, str_buf_path);
			}
			else
				free(array_buf);
		}
		free(buf);
	}
	return (0);
}

/**
 * sig_handler - function that catches the SIGINT signal on ctrl+C
 * and prints a new prompt on standard output
 * @signo: paramter handled by the signal library
 * Return: void
 */

void sig_handler(int signo)
{
	if (signo == SIGINT)
		_print("\n$ ");
}
