#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

/**
 * struct Built_in - Structure of command and function
 * @cmd: Command to be compared and function called
 * @fnc_cmd: Function to be called when command matches
 */

typedef struct Built_in
{
	char *cmd;
	int (*fnc_cmd)(char **argv, char **env, char **token_array);
} Built_in;

/*Custom String Function Prototypes*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strncat(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strchr(char *s, char c);
char *_strstr(char *haystack, char *needle);
char *str_concat(char *s1, char *s2);
char *_strdup(char *str);

/*Memory Allocation Prototypes*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_array_tokens(char **array_tokens);

/*User-defined Prototypes*/
char *get_path(char **env);
char **split_path(char *path_var);
char **split_user_input(char *user_input);
void handle_signal(int signum);
int handle_builtins(char **argv, char **env, char **token_array);
void err_msg(int fd, int num_cmd, char *s1, char *s2, char *s3);

/*Main program functions*/
void handle_interactions(char **argv, char **env, int *cmd_count);
void handle_non_interactive_mode(char **argv, char **env);
char **process_input(char **argv);
/*File inside handle-non_interactive*/

#endif /*SHELL_H*/
