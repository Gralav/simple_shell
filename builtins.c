#include "shell.h"
/**
 * exit_shell - This will run the builtin exit
 * @line: Line buffer of user input
 * @args: Arguments from user
 * @env: Environment
 * Return: Void
 */
void exit_shell(char **args, char *line, char **env)
{
	free(args);
	free(line);
	(void)env;
	exit(0);
}
/**
 * env_shell - Prints shell environment
 * @args: Arguments split from cmdline
 * @line: User input buffer
 * @env: Environment
 */

void env_shell(char **args, char *line, char **env)
{
	int size, i = 0;

	while (env[i] != NULL)
	{
		size = strlen(env[i]);
		write(1, env[i], size);
		write(1, "\n", 1);
		i++;
	}
	(void)args;
	(void)line;
}
