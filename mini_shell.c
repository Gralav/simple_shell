#include  "header_minishell.h"

/**
 * main - main function of our shell that will
 * receive the arguments in an infinite loop
 * Return: 0 if success
 */
int main(void)
{
	char *prompt = "caribbean@shell$ ", *buffer = NULL, *mypath = NULL,
	     **tokenized = NULL, *command = NULL;
	size_t bufsize = 0;
	int writecount = 0, getln;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			writecount = write(STDOUT_FILENO, prompt, 17);
			if (writecount == -1)
				exit(0);
		}
		getln = getline(&buffer, &bufsize, stdin);
		if (getln == -1)
		{
			free(buffer);
			if (isatty(STDIN_FILENO) != 0)
				write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}
		tokenized = tokenize(buffer);
		if (tokenized[0] != NULL)
		{
			execution2(tokenized, command, mypath, buffer);
		}
		else
			free(tokenized);
	}
	return (0);
}
