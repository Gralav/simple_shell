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
 * _strlen - function that returns the length of a string
 * @s: string defined in main or another function
 * Return: length of string
 */

int _strlen(char *s)
{
	int i = 0;

	while (*s != '\0')
		i++, s++;
	return (i);
}

/**
 * _putchar - writes the character c to standard output
 * @c: the character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print - function that prints on standard output
 * @str: string to be printed
 * Return: return of write, number of chars that write prints
 */

int _print(char *str)
{
	return (write(STDOUT_FILENO, str, _strlen(str)));
}

/**
 * print_number - function that converts an integer into a string
 * @n: integer passed from main or another function
 * Return: void
 */

void print_number(int n)
{
	unsigned int m;

	if (n > 9)
	{
		print_number(n / 10);
		_putchar('0' + (n % 10));
	}
	else if (n > -1)
	{
		_putchar('0' + n);
	}
	else if (n > -10)
	{
		_putchar('-');
		n = n * (-1);
		_putchar('0' + n);
	}
	else
	{
		_putchar('-');
		n = n * (-1);
		m = (unsigned int) n;
		print_number(m / 10);
		_putchar('0' + (m % 10));
	}
}
