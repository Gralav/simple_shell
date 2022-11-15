#include "shell.h"
/**
 * _getenv - gets env of input
 * @env: input
 * Return: env without =.
 */


char *_getenv(char *env)
{
	int i = 0, n = 0;
	char *temp, *res;

	while (environ[i] != NULL)
	{
		if (_strcmp(environ[i], env) == 0)
			temp = environ[i];
		i++;
	}
	while (temp[n] != '\0')
	{
		if (_strcmp(temp, env) == 0)
			res = _strspn(temp, "/");
		n++;
	}
	return (res);
}
