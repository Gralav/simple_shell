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
 * _strdup - function that returns a pointer to a newly allocated space
 * in memory, which contains a copy of the string given as a parameter
 * @str: string of chars
 * Return: address of the newly allocated memory
 */

char *_strdup(char *str)
{
	unsigned int len = 0;
	unsigned int i = 0, j = 0;
	char *str_copy = NULL;
	char *tmp = str;

	if (str == NULL)
		return (NULL);

	i = 0;
	while (*str++)
		i++;
	len = i;
	str = tmp;

	str_copy = malloc(len * sizeof(char) + 1);
	if (str_copy == NULL)
		return (NULL);

	j = 0;
	while (j < len)
	{
		str_copy[j] = str[j];
		j++;
	}
	str_copy[j] = '\0';
	return (str_copy);
}

/**
 * _memset - function that fills memory with a constant byte
 * @s: parameter defined in main, pointer to memory area
 * @b: parameter defined in main, constant byte
 * @n: parameter defined in main, number of bytes to be filled
 * Return: memory address of function (memory area)
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;
	char *tmp = s;

	for (i = 0; i < n; i++)
	{
		*s = b;
		s++;
	}
	s = tmp;
	return (s);
}

/**
 * _strcat - function that concatenates two strings
 * @dest: string passed by main or by another function
 * @src: string passed by main or by another function
 * Return: pointer to the concatenated string
 */

char *_strcat(char *dest, char *src)
{
	char *tmp = NULL;

	tmp = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest++ = '\0';
	dest = tmp;
	return (dest);
}

/**
 * _strcmp - function that compares two strings
 * @s1: pointer to string (or literal string) to be compared
 * @s2: pointer to string (or literal string) to be compared
 * Return: 0 if the two strings are identical, 1 otherwise
 */

int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (1);
}
