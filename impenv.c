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

	while (environ[i] != NULL)
	{
		if (strcmp(environ[i], env) == 0)
			temp = environ[i];
		i++;
	}
	while (temp[n] != '\0')
	{
		if (strcmp(temp, env) == 0)
			res = strstr(temp, "/");
		n++;
	}
	return (res);
}
