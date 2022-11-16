#include "header_minishell.h"

/**
 * _puts - prints a string
 * @str: string entering
 * Return: void
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _strcat - function to concatenate strings
 * @dest: destination string
 * @src: source string
 * Return: pointer of concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int a, b;

	for (a = 0; dest[a] != '\0'; a++)
	{
	}
	dest[a] = '/';
	a++;
	for (b = 0; src[b] != '\0'; b++)
	{
		dest[a] = src[b];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}
/**
 * _strstr - function to find a string within another string
 * @haystack: string where we will search
 * @needle: string to find
 * Return: string found
 */
char *_strstr(char *haystack, const char *needle)
{
	char *c;

	while (*haystack)
	{
		while (*needle == *haystack)
		{
			haystack++, needle++;
		}
		if (*needle == '\0')
		{
			if (*haystack == '=')
			{
				haystack++;
				c = haystack;
				return (c);
			}
			return (NULL);
		}
		haystack++;
	}
	return (NULL);
}
/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: integer
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i]; i++)
		if (s1[i] == '\0')
			return (0);
	return (s1[i] - s2[i]);
}
