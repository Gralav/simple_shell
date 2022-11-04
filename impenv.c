#include "shell.h"
/**
 * _impenv - gets env of input
 * @env: input
 * Return: env without =
 */
char *_impenv(char *env)
{
	int i = 0, n = 0;
	char *temp, *res;

	while (env[i] != NULL)
	{
		if (strcmp(environ[i], env) == 0)
			temp = environ[i];
		i++;
	}
	while (temp[n] != '\0')
	{
		if (_strcmp(temp, env) == 0)
			res = strstr(temp, "/");
		n++;
	}
	return (res);
}
