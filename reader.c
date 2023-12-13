#include "shell.h"
/**
 * reader - read user input
 * @cmd:pointer to user command
 * @s:length of command
 */

void reader(char *cmd, size_t s)
{
	if (fgets(cmd, s, stdin) == NULL)
	{
		perror("fgets");
		exit(FAIL);
	}

	if (cmd[strlen(cmd) - 1] == '\n')
		cmd[strlen(cmd) - 1] = '\0';
}

/**
 * printer - custom printf
 * @message: pointer to desired message
 */

void printer(const char *message)
{
	writer(message);
}
