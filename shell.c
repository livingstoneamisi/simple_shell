#include "shell.h"

/**
 * main - simple shell (Hsh)
 * @argc: Argument Counter
 * @argv: Value of Argument
 * Return: Exit Value By Status
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, **cmd;
	int ctr = 0, stat = 1, st = 0;

	if (argv[1] != NULL)
		read_file(argv[1], argv);
	signal(SIGINT, signal_to_handel);
	while (stat)
	{
		ctr++;
		if (isatty(STDIN_FILENO))
			prompt();
		input = _getline();
		if (input[0] == '\0')
		{
			continue;
		}
		history(input);
		cmd = parse_cmd(input);
		if (_strcmp(cmd[0], "exit") == 0)
		{
			exit_bul(cmd, input, argv, ctr);
		}
		else if (check_builtin(cmd) == 0)
		{
			st = handle_builtin(cmd, st);
			free_all(cmd, input);
			continue;
		}
		else
		{
			st = check_cmd(cmd, input, ctr, argv);

		}
		free_all(cmd, input);
	}
	return (stat);
}
/**
 * check_builtin - for checking builtin
 *
 * @cmd:command to check
 * Return: 0 Succes -1 Fail
 */
int check_builtin(char **cmd)
{
	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int x = 0;
		if (*cmd == NULL)
	{
		return (-1);
	}

	while ((fun + x)->command)
	{
		if (_strcmp(cmd[0], (fun + x)->command) == 0)
			return (0);
		x++;
	}
	return (-1);
}
/**
 * creat_envi - Creat Array of Enviroment Variable
 * @envi: Array of Enviroment Variable
 * Return: Void
 */
void creat_envi(char **envi)
{
	int x;

	for (x = 0; environ[x]; x++)
		envi[x] = _strdup(environ[x]);
	envi[x] = NULL;
}
