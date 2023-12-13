#include "shell.h"

/**
 * exit_bul - exit statue shell
 * @cmd: parsed command
 * @input: user input
 * @argv:program name
 * @c:execute count
 * Return: void (exit statue)
 */

void  exit_bul(char **cmd, char *input, char **argv, int c)
{
	int stat, x = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	while (cmd[1][x])
	{
		if (_isalpha(cmd[1][x++]) != 0)
		{
			_prerror(argv, c, cmd);
			break;
		}
		else
		{
			stat = _atoi(cmd[1]);
			free(input);
			free(cmd);
			exit(stat);
		}
	}
}


/**
 * change_dir - change directory
 * @cmd: parsed command
 * @er: statue last command executed
 * Return: 0 Succes 1 Failed (For Old Pwd Always 0 Case No Old PWD)
 */

int change_dir(char **cmd, __attribute__((unused))int er)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(cmd[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 * dis_env - display environment variable
 * @cmd:parsed command
 * @er:statue of last command executed
 * Return:Always 0
 */

int dis_env(__attribute__((unused)) char **cmd, __attribute__((unused)) int er)
{
size_t x;
	int len;

	for (x = 0; environ[x] != NULL; x++)
	{
		len = _strlen(environ[x]);
		write(1, environ[x], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * display_help - Displaying Help For Builtin
 * @cmd:Parsed Command
 * @er: Statue Of Last Command Excuted
 * Return: 0 Succes -1 Fail
 */

int display_help(char **cmd, __attribute__((unused))int er)
{
	int fd, fw, rd = 1;
	char s;

	fd = open(cmd[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (0);
	}
	while (rd > 0)
	{
		rd = read(fd, &s, 1);
		fw = write(STDOUT_FILENO, &s, rd);
		if (fw < 0)
		{
			return (-1);
		}
	}
	_putchar('\n');
	return (0);
}

/**
 * echo_bul - execute echo cases
 * @st:statue of last command executed
 * @cmd: Parsed Command
 * Return: Always 0 Or Excute Normal Echo
 */

int echo_bul(char **cmd, int st)
{
	char *path;
	unsigned int  pid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		print_number_in(st);
		PRINTER("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		print_number(pid);
		PRINTER("\n");

	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINTER(path);
		PRINTER("\n");
		free(path);

	}
	else
		return (print_echo(cmd));

	return (1);
}
