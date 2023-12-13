#include "shell.h"

/**
 * run - run acual commands
 * @cmd: user-input command
 */

void run(const char *cmd)
{
	pid_t c = fork();

	if (c == -1)
	{
		perror("Fork error!");
		exit(1);
	}
	else if (c == 0)
	{
		char *arg[] = {cmd, NULL};

		if (execvp(cmd, arg) == -1)
		{
			perror("Error executing command");
			_exit(1);
		}
	}
	else
	{
		int status;

		waitpid(c, &status, 0);
	}
}
