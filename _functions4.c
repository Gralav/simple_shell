#include "header_minishell.h"

/**
 * execution2 - This functios work
 * @tokenized: This is the arguments in a array of the strings
 * @command: This is my command
 * @buffer: This are the arguments in a single line or a strings
 * @mypath: This is the path of the enviroment
 * Return: Void
 */
void execution2(char **tokenized, char *command, char *mypath, char *buffer)
{
	int child_pid = 0, status, exitstatus = 0;

	if (tokenized[0] != NULL && (_sitrcmp(tokenized[0], "exit") == 0))
	{
		_puts("\n");
		free_grid(tokenized);
		free(buffer);
		exit(0);
	}
	mypath = _getenv("PATH");
	command = execution(tokenized, mypath);
	if (command != NULL)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			return;
		}
		if (child_pid == 0)
		{
			execve(command, tokenized, environ);
		}
		free(command);
		wait(&status);
		if (WIFEXITED(status))
		{
			exitstatus = WEXITSTATUS(status);
		}
	}
	else
		printerror(2, tokenized);
	(void)exitstatus;
	free_grid(tokenized);
}
