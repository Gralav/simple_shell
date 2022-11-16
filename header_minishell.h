#ifndef HEADER_MINI_SHELL_
#define HEADER_MINI_SHELL_

/**---Libraries---**/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>



/**---Prototypes functions to print---**/
void _puts(char *str);
int _putchar(char c);

/**---Prototypes functions to handle PATH and environment variables---**/
char *_getenv(const char *name);
char **tokenize(char *buffer);

/*void execution(char **tokeni, char *path);*/
void free_grid(char **grid);
char  *execution(char **tokeni, char *path);
void execution2(char **tokenized, char *comando, char *mypath, char *buffer);

/**---Prototypes functions to handle strings---**/
char *_strcat(char *dest, char *src);
char *_strstr(char *haystack, const char *needle);
int _strlen(char *s);
int _sitrcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int word_len(char *str);
int count_words(char *str);


/**---Delimitator---**/
#define DELIM " ,!¡¿?\'\"\n\t"



/**---Global variable environ---**/
extern char **environ;



/**---Function to print errors---**/
void printerror(int error, char **command);



#endif
