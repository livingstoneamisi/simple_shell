#include "shell.h"

/**
 * handle_builtin - Handle Builtin Command
 * @cmd: parsed command
 * @er: statue of last execute
 * Return: -1 Fail 0 Succes (Return :Excute Builtin)
 */

int handle_builtin(char **cmd, int er)
{
	 bul_t bil[] = {
		{"cd", change_dir},
		{"env", dis_env},
		{"help", display_help},
		{"echo", echo_bul},
		{"history", history_dis},
		{NULL, NULL}
	};
	int x = 0;

	while ((bil + x)->command)
	{
		if (_strcmp(cmd[0], (bil + x)->command) == 0)
		{
			return ((bil + x)->fun(cmd, er));
		}
		x++;
	}
	return (-1);
}

/**
 * check_cmd - Execute simple shell command (fork, wait, execute)
 *
 * @cmd: parsed command
 * @input: user input
 * @c: shell execution time case of command not found
 * @argv: program name
 * Return: 1 case command null -1 wrong command 0 command executed
 */

int check_cmd(char **cmd, char *input, int c, char **argv)
{
	int sts;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			path_cmd(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&sts);
	return (0);
}

/**
 * signal_to_handel - handle ^C
 * @sig: captured signal
 * Return: void
 */

void signal_to_handel(int sig)
{
	if (sig == SIGINT)
	{
		PRINTER("\n$ ");
	}
}
