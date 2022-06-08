#include "shell.h"

/**
 * _fork - fork code to execute a new command
 * @exe_code: execute a new command
 * @cmd_node: Command node pointer
 * @path: path recevied
 * @env: env variables
 *
 * Return: 1 on sucess, 0 on failure.
 */
int _fork(char *cmd_node, command_t *exe_code, char *path, char **env)
{
pid_t status, child_pid;
char *command;

if (*cmd_node->command[0] == '/')
command = cmd_node->command[0];
else
command = _which(path, cmd_node->command[0];
child_pid = fork();
if (child_pid == -1)
{
error_handler(, 102);
return (0);
}
if (child_pid == 0) /* child process */
{
if (_stat(exe_code, command))
_exec(command, cmd_node->command, env);
else
return (-1);
}
else
{
wait(&status);
}
return (0);
}
