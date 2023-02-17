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
 * prompt_n_read - function that prompts the user and reads the command line
 * in interactive or non-interactive mode
 * @path_str: pointer to the PATH string
 * @array_path: pointer to array of pointers to the PATH directories
 * Return: pointer to buf, command line buffer
 */

char *prompt_n_read(char *path_str, char **array_path)
{
	char *buf = NULL;
	size_t bufsize = 0;
	int i = 0, status = 0;

	if (isatty(STDIN_FILENO) == 1)
		_print("$ ");
	status = getline(&buf, &bufsize, stdin);
	if (status == -1)
	{
		free(buf);
		free(array_path);
		free(path_str);
		if (isatty(STDIN_FILENO) == 1)
			_print("\n");
		exit(0);
	}
	for (i = 0; buf[i] != '\0'; i++)
	{
		if (buf[0] == '#' || (buf[i] == ' ' && buf[i + 1] == '#'))
		{
			buf[i] = '\0';
			break;
		}
	}
	return (buf);
}

/**
 * split_buf - function that tokenizes a string with spaces, tabs and new lines
 * as delimiters
 * @buf: command line passed in by the user on standard input, string to be
 * parsed
 * Return: double pointer to an array (array of pointers to strings consisting
 * of the individual strings typed in by the user)
 */

char **split_buf(char *buf)
{
	int i = 0, count = 0;
	char *token = NULL;
	char **array_buf = NULL;

	count = token_count_buf(buf);
	if (count == 0)
		return (NULL);
	array_buf = malloc(sizeof(char *) * (count + 1));
	if (array_buf == NULL)
		exit(1);
	token = strtok(buf, " \n\t");
	while (token != NULL)
	{
		array_buf[i] = token;
		i++;
		token = strtok(NULL, " \n\t");
	}
	array_buf[i] = NULL;
	return (array_buf);
}

/**
 * token_count_buf - function that counts the number of strings typed in by the
 * user (in buf)
 * @buf: command line passed in by the user on standard input, string to be
 * parsed
 * Return: token/string count
 */

int token_count_buf(char *buf)
{
	int i = 0, count = 0;

	while (*buf != '\0')
	{
		if (*buf == ' ' || *buf == '\t')
			count++;
		i++, buf++;
	}
	count++;
	return (count);
}
