#include "shell.h"


/**
 * token - tokenizer
 * @cmd: pointer to command string
 * @args: storage array
 */
void token(const char *cmd, char *args[])
{
	int a = 0;
	char *token = strtok((char *)cmd, " ");

	while (token != NULL && a < MAXARG - 1)
	{
		args[a++] = token;
		token = strtok(NULL, " ");
	}

	args[a] = NULL;
}

/**
 * exec - actual runner
 * @args:array of tokens
 */
void exec(char *args[])
{
	pid_t c = fork();

	if (c == -1)
	{
		perror("Fork Error!");
		exit(FAIL);
	}
	else if (c == 0)
	{
		char *path = NULL;
		char *env_path = getenv("PATH");
		char *dir = strtok(env_path, ":");

		while (dir != NULL)
		{
			char *tmp = malloc(strlen(dir) + strlen(args[0]) + 2);

			strcpy(tmp, dir);
			strcat(tmp, "/");
			strcat(tmp, args[0]);
			if (access(tmp, X_OK) == 0)
			{
				path = tmp;
				break;
			}
			free(tmp);
			dir = strtok(NULL, ":");
		}
		path = path ? path : args[0];
		execve(path, args, NULL);
		perror("execve");
		exit(FAIL);
	}
	else
	{
		int s;

		waitpid(c, &s, 0);
	}
}

/**
 * run - run acual commands
 * @cmd: user-input command
 */

void run(const char *cmd)
{
	char *args[MAXARG];

	token(cmd, args);
	exec(args);
}
