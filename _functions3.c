#include "header_minishell.h"

/**
 * _strcpy - copies the string pointed to by src, to the buffer
 * @dest: destination
 * @src: source
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = src[i];
	return (dest);
}
/**
 * free_grid - function to free an array memory
 * @grid: array of strings
 * Return: void
 */
void free_grid(char **grid)
{
	int i;

	for (i = 0; grid[i] != NULL ; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
/**
 * word_len - function to count number of letters of
 *            each word
 * Return: number of letters of tje word
 */
int word_len(char *str)
{
	int index = 0, len = 0;

	while (*(str + index) && *(str + index) != ' ')
	{
		len++;
		index++;
	}
	return (len);
}
/**
 * count_words - functin to count number of words
 * @str: string
 * Return: number of words
 */
int count_words(char *str)
{
	int index = 0, words = 0, len = 0;

	for (index = 0; *(str + index); index++)
		len++;
	for (index = 0; index < len; index++)
	{
		if (*(str + index) != ' ')
		{
			words++;
			index += word_len(str + index);
		}
	}
	return (words);
}
