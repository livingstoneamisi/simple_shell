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
		exit(FAIL);
	}
	else if (c == 0)
	{
		execlp(cmd, cmd, (char *)NULL);
		perror("execlp");
		exit(FAIL);
	}
	else
	{
		int status;

		waitpid(c, &status, 0);
	}
}
