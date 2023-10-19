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
 * _getenv - function that gets an environment variable
 * and returns a pointer to that variable (here, PATH)
 * @name: pointer to the variable name on target (here, PATH)
 * Return: pointer to the actual environment variable
 */

char *_getenv(const char *name)
{
	int i = 0, j = 0, flag = 0;
	char *path_str = NULL;

	while (environ[i] != NULL)
	{
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (environ[i][j] == name[j])
			{
				flag = 0;
			}
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			path_str = _strdup(environ[i]);
			return (path_str);
		}
		i++;
	}
	return (NULL);
}

/**
 * split_path - function that tokenizes the PATH string, making token pointers
 * to each PATH directories found
 * @path_str: pointer to the PATH string to be parsed, passed by main
 * Return: double pointer to an array (array of pointers to strings consisting
 * of the individual PATH directories)
 */

char **split_path(char *path_str)
{
	int i = 0, count = 0;
	char *token = NULL;
	char **array_path = NULL;

	count = token_count_path(path_str);
	if (count == 0)
		return (NULL);
	array_path = malloc(sizeof(char *) * (count + 1));
	if (array_path == NULL)
		exit(1);
	token = strtok(path_str, "=");
	token = strtok(NULL, ":\n");
	while (token != NULL)
	{
		array_path[i] = token;
		i++;
		token = strtok(NULL, ":\n");
	}
	array_path[i] = NULL;
	return (array_path);
}

/**
 * token_count_path - function that counts the number of directories in the
 * PATH string
 * @path_str: pointer to the PATH string to be parsed, passed by main
 * Return: token/directory count
 */

int token_count_path(char *path_str)
{
	int i = 0, count = 0;

	if (path_str == NULL || path_str[i] == '\0')
		return (0);
	while (*path_str != '\0')
	{
		if (*path_str == ':')
			count++;
		i++, path_str++;
	}
	count++;
	return (count);
}

/**
 * buf_path_cat - function that concatenates buf (user cmd), '/' and
 * the path directories, one at a time
 * @counter: tracking the number of commands that have been executed or failed
 * @av: ./file_name
 * @array_buf: pointer to the first string of array_buf (array_buf[0])
 * @array_path: pointer to array of pointers to the PATH directories
 * Return: pointer to the concatenated strings
 */

char *buf_path_cat(int counter, char *av, char *array_buf, char **array_path)
{
	char *str_buf_path = NULL;
	int char_count = 0, i = 0, status = 0;

	while (array_path[i] != NULL)
	{
		str_buf_path = malloc((_strlen(array_buf) +
				       _strlen(array_path[i])) * sizeof(char) + 2);
		if (str_buf_path == NULL)
			exit(1);
		char_count = (_strlen(array_buf) + _strlen(array_path[i])) + 2;
		_memset(str_buf_path, 0, char_count);
		_strcat(str_buf_path, array_path[i]);
		_strcat(str_buf_path, "/");
		_strcat(str_buf_path, array_buf);
		str_buf_path[char_count - 1] = '\0';
		i++;

		status = _status(str_buf_path);
		if (status == -1)
		{
			free(str_buf_path);
		}
		else if (status == 0)
			break;
	}
	if (status == -1)
	{
		_print(av);
		_print(": ");
		print_number(counter);
		_print(": ");
		_print(array_buf);
		_print(": not found\n");
		return (NULL);
	}
	return (str_buf_path);
}

/**
 * _status - function that checks the status of a file
 * @str_buf_path: pointer to the concatenated string
 * consisting of buf (user cmd), '/' and the path directories
 * Return: 0 if the file is found by the stat function, -1 otherwise
 */

int _status(char *str_buf_path)
{
	struct stat st;

	if (stat(str_buf_path, &st) != 0)
	{
		return (-1);
	}
	return (0);
}
