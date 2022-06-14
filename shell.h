#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
/*MACROS*/
#define BUFSIZE 1024
#define DELIM "\t\r\n\a"
#define PRINTER(c) (write(STDOUT_FILENO, c, _strlen(c)))
/**
 * struct error_msg - An structure for each error message
 *
 * @ecode: error code
 * @msg: pointer to error message
 * @size: error message length.
 */
typedef struct error_msg
{
	int ecode;
	char *msg;
	int  size;
} error_msg_t;

/**
 * struct built_s - Builtings commands
 * @command: command name.
 * @f: function to call.
 *
 * Description: Longer description
 */
typedef struct built_s
{
	char *command;
	void (*f)(char **);
} built_t;

/**
 * struct history - An structure for each command readed
 *
 * @id_h: error code
 * @comms: Commands
 * @prev: Previous element
 * @next: Next element
 */

typedef struct history
{
	unsigned int id_h;
	char *comms;
	struct history *prev;
	struct history *next;
} history_t;

/**
 * struct command_s - An structure for each command
 *
 * @command: command with arguments.
 * @next: pointer to next command.
 */
typedef struct command_s
{
	char **command;
	struct command_s *next;
} command_t;

/* Shell functions */
command_t **_prompt(char *, char *);
int _fork(char *, command_t *, char *, char **);
int _stat(char *, char *);
int _exec(char *, char **, char **);

/* Utilities */
char *read_line(void);
char *_strtok(char *str, const char *tok);
int _strlen(char *s);
command_t *_parser_cmd(char *, char *);
size_t _parser_arg(char *, char **, size_t *);
void print_char_pointer_arr(char **, size_t);
int add_nodeint(history_t **head, char *str);
char *_strdup(char *str);
void free_listint(history_t *head);
void print_listint(const history_t *);
char *find_path(char **);
char *_strstr(char *haystack, char *needle);
void print_env(char **);
char *_which(char *p_rec, char *first_arg);
char *string_nconcat(char *s1, char *s2, unsigned int n);
int _strncmp(const char *s1, const char *s2, size_t n);
void _exit_func(char **);
int verif_built_comm(char *str, char **env);
char *_strcat(char *dest, char *src);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* Error handler */
void error_handler(char *, int);
void error_handler_set_default(int, char *);

/* Command Utilities */
command_t *new_cmd_node(char *);
void add_tok_to_cmd(char *, command_t *, size_t, char *);
/*envirnment*/
extern char **environ;
#endif
/*bul fun*/
void hashtag_handle(char *buff);
/*input helpers*/
char *get_args(char *line, int *exe_ret);
int call_args(char **args, char **front, int *exe_ret);
int run_args(char **args, char **front, int *exe_ret);
int handle_args(int *exe_ret);
int check_args(char **args);
